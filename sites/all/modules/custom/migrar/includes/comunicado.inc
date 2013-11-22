<?php
/**
 * @file
 * Este archivo define la clase que migra comunicados de prensa
 *
 * La clase se basa en BaseMigracion e implementa BaseMigracionInterface.
 * BaseMigracion extiende desde el framework que provee el modulo migrate.
 */
class ComunicadoXMLMigration extends BaseMigracion implements BaseMigracionInterface {

  /**
  * Constructor sin parametros.
  */
  public function __construct() {
    $this->type = "comunicado";
    $this->init();
    $this->description = t('Importar comunicados desde archivo XML');


    $this->addFieldMapping('created', 'fecha');
    $this->addFieldMapping('changed', 'fecha_actualizacion');

    //$this->addFieldMapping('field_pr_image', 'imagen');

    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_pr_date', 'fecha_actualizacion')
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
    //module_load_include('inc', 'node', 'node.admin');

    $is_original = is_numeric(trim($current_row->xml->id_sade_maestro));

    $id_sade = (int) $current_row->xml->id_sade;
    $imagesComunicado = new ImagenesComunicado();
    $imagenes = $imagesComunicado->getImagenesByIdSade($id_sade);
    unset($imagesComunicado);

    $archivosComunicado = new ArchivosComunicado();
    $archivos = $archivosComunicado->getArchivosByIdSade($id_sade);
    if($is_original){
      $traducciones = $this->getComunicadosTraducciones($id_sade);
      foreach($traducciones as $id_sade_translation){
        $archivos += $archivosComunicado->getArchivosByIdSade($id_sade_translation);
      }
    }
    unset($archivosComunicado);

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
      $current_imagen = $this->insertarImagen($imagen);
      if($current_imagen !== FALSE){
        $current_row->imagen = $current_imagen;
      }
    }

    if(is_array($archivos)){
      foreach($archivos as $archivo){
        $current_archivo = $this->insertarArchivo($archivo);
        $current_row->archivos[] = $current_archivo;
      }
    }

    return TRUE;
  }



  public function complete($entity, stdClass $row) {
    $lng = LANGUAGE_NONE;

    $image = $row->imagen;
    $fid = (int) $image->fid;

    if($fid > 0){
      $field_image = array($lng => array('0' => (array)$image));
      $entity->field_pr_image = $field_image;
    }
    $files = $row->archivos;
    if(count($files) > 0){
      $entity->field_pr_files = array();
      $entity->field_pr_files[$lng] = array();
      $i = 0;
      foreach($files as $file){
        $entity->field_pr_files[$lng][$i++] = (array)$file;
      }
    }
    else{
      //drush_print("esto no tenia archivos");
    }

    $entity->uid = $this->retrieveUid($row);

    node_save($entity);
  }

 /*
 public function prepareRollback($entity_id) {
    parent::prepareRollback();

  }
 */

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
      'mail_grupo_usuarios' => t('Email de contacto'),
      'id_division'         => t('Id de la division'),
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

    self::fileFieldUnmigrated('field_pr_files', $unmgtDests);
    self::imageFieldUnmigrated('field_pr_image', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_special_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_unbis', $unmgtDests);

    unset($unmgtDests[array_search ( 'created' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'changed' , $unmgtDests )]);

    $unmgtDests[] = 'field_pr_country';

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
      'title_field'          => array('field' => 'titulo'),
      'title_field:language' => array('field' => 'idioma'),
      'language'        => array('field' => 'idioma'),
      'field_pr_body'   => array('field' => 'cuerpo', 'callback' => 'filterHTML'),
      'field_pr_body:language'   => array('field' => 'idioma'),
      'field_pr_teaser' => array('field' => 'bajada', 'callback' => 'filterHTML'),
      'field_pr_teaser:language' => array('field' => 'idioma'),
      'field_pr_contact_person' => array('field' => 'mail_grupo_usuarios'),
      'field_pr_contact_intitutional' => array('field' => 'mail_grupo_usuarios'),
      'field_pr_contact_intitutional:language' => array('field' => 'idioma'),
      'field_pr_contact_person:language' => array('field' => 'idioma'),
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
      'field_pr_body:format' => 'filtered_html',
    );
  }



  protected function getXMLFeed() {

  }



  protected function insertarTraduccion($currentRow){
    /****   Crear el nodo   ****/
    $id_sade = $currentRow->xml->id_sade_maestro;
    $field_name = "field_id_sade";
    $node = $this->loadNodeByIdSade($id_sade, $field_name);
    if(!$node) return FALSE;

    $teaser = check_plain($currentRow->xml->bajada);
    $body   = $this->filterHTML($currentRow->xml->cuerpo);
    $title  = check_plain($currentRow->xml->titulo);

    $idioma = (string)$currentRow->xml->idioma;

    /* Se guarda cada uno de los campos traducidos para el nodo padre */
    $this->setNodeTitle($node, $idioma, $title);
    $this->setNodeBody($node, $idioma, $body, 'field_pr_body');
    $this->setNodeTeaser($node, $idioma, $teaser, 'field_pr_teaser');

    $this->addUserToNodeByEmail($node, $currentRow);

    node_save($node);

    /* se inserta la nueva traduccion como "hecha" */
    $this->insertEntityTranslation($node, $idioma);

    /****   Crear alias para el nuevo nodo en el nuevo idioma    ****/
    $this->savePath($node, $idioma);
  }


  public function getComunicadosTraducciones($id_sade){
    $path_xml = $this->getXMLFilePath();
    $comunicados = simplexml_load_file($path_xml);

    $traducciones = array();
    foreach($comunicados as $comunicado){
      $id_sade_comunicado = (int)$comunicado->id_sade_maestro;
      if($id_sade == $id_sade_comunicado){
        $traducciones[] = (int)$comunicado->id_sade;
      }
    }

    return $traducciones;
  }


}