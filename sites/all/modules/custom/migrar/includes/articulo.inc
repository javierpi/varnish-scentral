<?php
/**
 * @file
 * Este archivo define la clase que migra articulos
 *
 * La clase se basa en BaseMigracion e implementa BaseMigracionInterface.
 * BaseMigracion extiende desde el framework que provee el modulo migrate.
 */

$articulos_migrados = 0;

define("MENSAJE_SECRETARIO_GENERAL", 1);
define("COLUMNA_OPINON", 2);


class ArticuloXMLMigration extends BaseMigracion implements BaseMigracionInterface {
  const MENSAJE_SECRETARIO_GENERAL = 1;
  const COLUMNA_OPINON             = 2;
  /**
  * Constructor sin parametros.
  */
  public function __construct() {
    $this->type = "articulo";
    $this->init();
    $this->description = t('Importar articulos desde archivo XML');

    $this->addFieldMapping('created', 'fecha');
    $this->addFieldMapping('changed', 'fecha_actualizacion');

    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_article_date', 'fecha_actualizacion')
      ->xpath('fecha_actualizacion')
      ->arguments($arguments);
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
    global $articulos_migrados;
    drush_print ($articulos_migrados++);

    $uid = $this->retrieveUid($current_row);
    $is_original = is_numeric(trim($current_row->xml->id_sade_maestro));
    $idioma = (string)$current_row->xml->idioma;


    $id_sade = (int) $current_row->xml->id_sade;
    $imagesArticulo = new Imagenes('imagenesArticulo');
    $imagenes = $imagesArticulo->getImagenesByIdSade($id_sade);
    unset($imagesArticulo);

    $archivosArticulo = new Archivos('archivosArticulo');
    $archivos = $archivosArticulo->getArchivosByIdSade($id_sade);
    if($is_original){
      $traducciones = $this->getTraducciones($id_sade);
      foreach($traducciones as $id_sade_translation){
        $archivos += $archivosArticulo->getArchivosByIdSade($id_sade_translation);
      }
    }
    unset($archivosArticulo);



    $tipo = (int) $current_row->xml->tipodearticulo;
    if($tipo == self::MENSAJE_SECRETARIO_GENERAL) {
      $current_row->xml->tipodearticulo = 1;
    }
    else if($tipo == self::COLUMNA_OPINON){
      $current_row->xml->tipodearticulo = 0;
    }
    else {
      /**
       * Si no es una columna o un mensaje, no se migra.
       */
      return FALSE;
    }
    $aux = explode(" ", $current_row->xml->fecha);
    $pieces = explode("-", $aux[0]);
    $created = mktime(0, 0, 0, $pieces[1], $pieces[0], $pieces[2]);

    $current_row->fecha = $created;

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
      'titulo'              => t('Titulo del comunicado'),
      'bajada'              => t('Summary de body'),
      //'epigrafe'            => t('Fecha y hora?'),
      'fecha'               => t('created'),
      'fecha_actualizacion' => t('updated'),
      'cuerpo'              => t('body'),
      'idioma'              => t('Idioma'),

      'autor'                 =>  t('autor del articulo?'),
      'tipodearticulo'        => t('Columna de opinion o articulo'),
      'SADE_misc_division'    => t('division publicadora'),
      'contacto_persona'      => t('persona de contacto para la publicacion'),
      'contacto_organizacion' => t('contacto organizacion'),
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

    self::fileFieldUnmigrated('field_article_files', $unmgtDests);

    self::imageFieldUnmigrated('field_article_image', $unmgtDests);

    self::taxonomyFieldUnmigrated('field_article_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_article_unbis', $unmgtDests);

    unset($unmgtDests[array_search ( 'created' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'changed' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'language' , $unmgtDests )]);

    $unmgtDests[] = 'field_article_country';

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
      'field_article_body' => array('field' => 'cuerpo', 'callback' => 'filterHTML'),
      'field_article_body:language' => array('field' => 'idioma'),

      'field_article_teaser' => array('field' => 'bajada', 'callback' => 'filterHTML'),
      'field_article_teaser:language' => array('field' => 'idioma'),

      'field_article_author' => array('field' => 'autor'),
      'field_article_author:language' => array('field' => 'idioma'),
      'field_article_type'   => array('field' => 'tipodearticulo'),
      'field_article_id_sade' => array('field' => 'id_sade'),
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
      'field_article_body:format' => 'filtered_html',
    );
  }

  public function getXMLFeed() {

  }


  public function complete($entity, stdClass $row) {
    drush_print ("nid: " . $entity->nid . " -- sade_id: " . $row->xml->id_sade);
    $lng = LANGUAGE_NONE;
    $uid = $this->retrieveUid($row);

    $fid = 0;
    if(isset($row->imagen)){
      $image = $row->imagen;
      $fid = (int) $image->fid;
    }

    if($fid > 0){
      $image->uid = $uid;
      $field_image = array($lng => array('0' => (array)$image));
      $entity->field_article_image = $field_image;
    }
    $files = $row->archivos;
    if(count($files) > 0){
      $entity->field_article_files = array();
      $entity->field_article_files[$lng] = array();
      $i = 0;
      foreach($files as $file){
        $file->uid = $uid;
        $entity->field_article_files[$lng][$i++] = (array)$file;
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
    $date   = $currentRow->xml->fecha;


    drush_print_r("nid: " . $node->nid . " -- sade_id: " . $id_sade . " -- lang: " . $idioma);

    /* Se guarda cada uno de los campos traducidos para el nodo padre */
    $this->setNodeTitle($node, $idioma, $title);
    $this->setNodeBody($node, $idioma, $body, 'field_pr_body');
    $this->setNodeTeaser($node, $idioma, $teaser, 'field_pr_teaser');
    $this->setNodeDate($node, $idioma, $date, 'field_pr_date');

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