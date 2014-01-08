<?php

require_once 'Imagenes.php';

$noticias_migradas = 0;

/**
 * @file
 * Este archivo define la clase que migra noticias
 *
 * La clase se basa en BaseMigracion e implementa BaseMigracionInterface.
 * BaseMigracion extiende desde el framework que provee el modulo migrate.
 */
class NoticiaXMLMigration extends BaseMigracion implements BaseMigracionInterface {

  /*
   * El tipo de contenido "News" tiene 3 tipos. El tipo "Noticia" es el 3
   */
  const ID_NOTICIA = 3;


  /**
  * Constructor sin parametros.
  */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->type = "noticia";
    $this->init();
    $this->description = t('Importar noticias desde archivo XML');

    $this->addFieldMapping('created', 'fecha');
    $this->addFieldMapping('field_news_date', 'fecha');
    $this->addFieldMapping('changed', 'fecha_actualizacion');

  }



  /**
   * Esta funcion se usa para preparar algunos atributos antes de insercion.
   *
   * Existen atributos tales como fechas o atributos multivalorados que
   * requieren un proceso antes de ser insertados en la base de datos. En esta
   * funcion se hace ese proceso.
   *
   * @param mixed $current_row
   * @return boolean
   */
  public function prepareRow($current_row) {
    global $noticias_migradas;
    drush_print ($noticias_migradas++);
    $is_original = is_numeric(trim($current_row->xml->id_sade_maestro));
    $idioma = (string)$current_row->xml->idioma;

    $id_sade = (int) $current_row->xml->id_sade;
    $imagesNoticia = new Imagenes('noticia');
    $imagenes = $imagesNoticia->getImagenesByIdSade($id_sade);
    unset($imagesNoticia);

    //$archivosNoticia = new Archivos('archivosNoticia');
    $archivosNoticia = new Archivos('noticia');
    $archivos = $archivosNoticia->getArchivosByIdSade($id_sade);
    if($is_original){
      $traducciones = $this->getTraducciones($id_sade);
      if(count($traducciones)){
        drush_print("tiene traducciones, sade_id: " . $id_sade);
      }
      foreach($traducciones as $id_sade_translation){
        $archivos += $archivosNoticia->getArchivosByIdSade($id_sade_translation);
      }
    }
    unset($archivosNoticia);

    //drush_print_r($current_row->xml->fecha);
    //drush_print_r($current_row->xml->fecha_actualizacion);

    $aux = explode(" ", $current_row->xml->fecha);
    $pieces = explode("-", $aux[0]);
    $created = mktime(0, 0, 0, $pieces[1], $pieces[2], $pieces[0]);

    $current_row->fecha           = $created;
    $current_row->field_news_date = $pieces[2] . "-" . $pieces[1] . "-" . $pieces[0] . "T00:00:00";

    $aux2 = explode(" ", $current_row->xml->fecha_actualizacion);
    $pieces2 = explode("-", $aux2[0]);
    $changed = mktime(0, 0, 0, $pieces2[1], $pieces2[0], $pieces2[2]);

    $current_row->fecha_actualizacion = $changed;
    if($is_original){
      $this->insertarTraduccion($current_row);

      return FALSE;
    }
    else{
      $current_row->xml->id_sade_maestro = 0;
    }

    if(count($imagenes) > 0){
      /* Solo se inserta una imagen */
      $imagen = array_shift($imagenes);
      $current_imagen = $this->insertarImagen($imagen, $idioma, $uid);
      if($current_imagen !== FALSE){
        $current_row->imagen = $current_imagen;
      }
    }

    if(is_array($archivos)){
      foreach($archivos as $archivo){
        $current_archivo = $this->insertarArchivo($archivo, $uid);
        $current_row->archivos[] = $current_archivo;
      }
    }

    return TRUE;
  }



 /**
  * Funcion que describe los campos del xml.
  *
  * @return array
  */
  static public function getXMLFields() {
    return array(
      'id_sade'             => t('Identificador de SADE'),
      'id_sade_maestro'     => t('Identificador de traduccion de SADE'),
      'titulo'              => t('Titulo del comunicado'),
      'bajada'              => t('Summary de body'),
      'fecha'               => t('created'),
      'fecha_actualizacion' => t('updated'),
      'cuerpo'              => t('body'),
      'idioma'              => t('Idioma'),
      'area_de_trabajo'     => t('field_news_area_ref?'),
      'mail_grupo_usuarios' => t('Email de duenio del contenido'),
      'id_division'         => t('Identificador de la division duenia')
    );
  }



  /**
  * Devuelve un arreglo con los campos que no estan incluidos en la migracion.
  *
  * @return array
  */
  static protected function getUnmigratedDestinations() {
    /* $unmgDests son los campos no migrados con correspondencia por defecto */
    $unmgtDests = array();
    $unmgtDests += parent::getUnmigratedDestinations();


    self::taxonomyFieldUnmigrated('field_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_special_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_unbis', $unmgtDests);

    $unmgtDests[] = 'field_country';
    $unmgtDests[] = 'field_news_observatories';
    $unmgtDests[] = 'field_news_subsidiary_bodies';

    unset($unmgtDests[array_search ( 'created' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'changed' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'language' , $unmgtDests )]);

    return $unmgtDests;
  }



 /**
  * Funcion que entrega las equivalencias 1-1. Puede llamar un callback.
  *
  * La funcion de callback es necesaria solo en los casos en que se requiere
  * procesar los datos.
  * Si el valor de 'field' es false, entonces el campo no es migrado.
  * Si en el arreglo que se pasa como parametro existe la llave "callback"
  * entonces se va a llamar a esa funcion como preproceso de los datos.
  *
  * @return array
  */
  static public function getNormalEquivalences() {

    return array(
      'title'           => array('field' => 'titulo', 'callback' => ''),
      'language'        => array('field' => 'idioma', 'callback' => ''),
      'field_news_body'   => array('field' => 'cuerpo', 'callback' => 'filterHTML'),
      'field_news_body:language'   => array('field' => 'idioma'),
      'field_news_area_ref'   => array('field' => 'area_de_trabajo'),
      'field_news_teaser' => array('field' => 'bajada', 'callback' => 'filterHTML'),
      'field_news_teaser:language' => array('field' => 'idioma'),

      'title_field' => array('field' => 'titulo'),
      'title_field:language' => array('field' => 'idioma'),
      'field_id_sade' => array('field' => 'id_sade'),
      'field_id_sade_maestro' => array('field' => 'id_sade_maestro'),
    );
  }



 /**
  * Devuelve un arreglo con todos los campos que tienen un valor fijo.
  *
  * Si un valor es independiente del xml entonces una de las opciones posiles
  * es que sea fijo. Si tal es el caso, esta es la funcion que debe usarse.
  *
  * @return type
  */
  static public function getDefaultEquivalences() {

    return array(
      'translate' => TRUE,
      'field_news_body:format' => 'filtered_html',
      'field_news_type' => self::ID_NOTICIA,
    );
  }



  protected function getXMLFeed() {

  }



  public function complete($entity, stdClass $row) {
    drush_print ("nid: " . $entity->nid . " -- sade_id: " . $row->xml->id_sade);
    $lng = $entity->language;
    $uid = $this->retrieveUid($row);

    $fid = 0;
    if(isset($row->imagen)){
      $image = $row->imagen;
      $fid = (int) $image->fid;
    }

    if($fid > 0){
      $image->uid = $uid;
      $field_image = array($lng => array('0' => (array)$image));
      $entity->field_news_image = $field_image;
    }
    $files = $row->archivos;
    if(count($files) > 0){
      $entity->field_news_files = array();
      $entity->field_news_files[$lng] = array();
      $i = 0;
      foreach($files as $file){
        $file->uid = $uid;
        $entity->field_news_files[$lng][$i++] = (array)$file;
      }
    }
    else{
      //drush_print("esto no tenia archivos");
    }

    $entity->uid = $uid;

    node_save($entity);
  }


  protected function insertarTraduccion($currentRow){

    /****   Crear el nodo   ****/
    $id_sade_maestro = $currentRow->xml->id_sade_maestro;
    $id_sade         = $currentRow->xml->id_sade;
    $field_name = "field_id_sade";
    $node = $this->loadNodeByIdSade($id_sade_maestro, $field_name);
    if(!$node) return FALSE;
    $idioma = (string)$currentRow->xml->idioma;

    if($idioma == $node->language) return FALSE;

    $teaser = check_plain($currentRow->xml->bajada);
    $body   = $this->filterHTML($currentRow->xml->cuerpo);
    $title  = check_plain($currentRow->xml->titulo);
    //$date   = $currentRow->xml->fecha;


    drush_print_r("nid: " . $node->nid . " -- sade_id: " . $id_sade . " -- lang: " . $idioma);

    /* Se guarda cada uno de los campos traducidos para el nodo padre */
    $this->setNodeTitle($node, $idioma, $title);
    $this->setNodeBody($node, $idioma, $body, 'field_news_body');
    $this->setNodeTeaser($node, $idioma, $teaser, 'field_news_teaser');
    //$this->setNodeDate($node, $idioma, $date, 'field_pr_date');

    $node->field_id_sade[$idioma][0]['value']         = $id_sade;
    $node->field_id_sade_maestro[$idioma][0]['value'] = $id_sade_maestro;

    $this->addUserToNodeByEmail($node, $currentRow);

    node_save($node);

    /* se inserta la nueva traduccion como "hecha" */
    $this->insertEntityTranslation($node, $idioma);

    /****   Crear alias para el nuevo nodo en el nuevo idioma    ****/
    $node_path = $this->generatePath($node, $idioma);
    if($node_path){
      path_save($node_path);
    }


    //cambiar los apostrofes de titulo en la base de datos


    $search = "&#039;";
    $replace = "'";

    db_update('field_data_title_field')
      ->expression(
          'title_field_value', 'replace(title_field_value, :search, :replace)',
          array(
            ':search'  => $search,
            ':replace' => $replace
          )
        )
      ->execute()
      ;

  }
}