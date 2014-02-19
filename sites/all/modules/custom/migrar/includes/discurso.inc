<?php
$discursos_migrados = 0;

class DiscursoXMLMigration extends BaseMigracion implements BaseMigracionInterface {
  const PRESENTATION_IMAGES_PATH = "/sites/default/files/styles/[style]/public/presentation/images";
  const PRESENTATION_TYPE_PRESENTATION = 1;
  const PRESENTATION_TYPE_SPEECH       = 2;

  /**
  * Constructor sin parametros.
  */
  public function __construct() {
    $this->type = "discurso";
    $this->init();
    $this->description = t('Importar discursos desde archivo XML');

    $this->addFieldMapping('created', 'fecha');
    $this->addFieldMapping('changed', 'fecha_actualizacion');

    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_presentation_date', 'fecha_actualizacion')
      ->xpath('fecha_actualizacion')
      ->arguments($arguments);
  }


  public function prepareRow($current_row) {
    global $discursos_migrados;
    drush_print ($discursos_migrados++);

    $uid = $this->retrieveUid($current_row);
    $is_original = is_numeric(trim($current_row->xml->id_sade_maestro));
    $idioma = (string)$current_row->xml->idioma;


    $id_sade = (int) $current_row->xml->id_sade;
    $imagesDiscurso = new Imagenes('imagenesDiscurso');
    $imagenes = $imagesDiscurso->getImagenesByIdSade($id_sade);
    unset($imagesDiscurso);

    $archivosDiscurso = new Archivos('archivosDiscurso');
    $archivos = $archivosDiscurso->getArchivosByIdSade($id_sade);
    if($is_original){
      $traducciones = $this->getTraducciones($id_sade);
      foreach($traducciones as $id_sade_translation){
        $archivos += $archivosDiscurso->getArchivosByIdSade($id_sade_translation);
      }
    }
    unset($archivosDiscurso);

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
      'idioma'              => t('Idioma'),
      'id_division'         => t('Division publicadora'),
      'fecha'               => t('created'),
      'fecha_actualizacion' => t('updated'),
      'titulo'              => t('Titulo del comunicado'),
      'cuerpo'              => t('body'),
      'autor'               =>  t('autor del discurso'),
      'lugar_pais_iso2'     =>  t('codigo ISO2 del pais'),
      'lugar_ciudad'        =>  t('Nombre de la ciudad'),
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

    self::fileFieldUnmigrated('field_presentation_files', $unmgtDests);

    self::imageFieldUnmigrated('field_presentation_image', $unmgtDests);

    self::taxonomyFieldUnmigrated('field_special_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_unbis', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_topic', $unmgtDests);

    self::urlFieldUnmigrated('field_presentation_url_reference', $unmgtDests);

    unset($unmgtDests[array_search ( 'created' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'changed' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'language' , $unmgtDests )]);

    $unmgtDests[] = 'field_presentation_event_ref';
    $unmgtDests[] = 'field_related';

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
      'title_field'           => array('field' => 'titulo', 'callback' => ''),
      'title_field:language' => array('field' => 'idioma'),
      'language'        => array('field' => 'idioma', 'callback' => ''),
      'field_presentation_body' => array('field' => 'cuerpo', 'callback' => 'filterHTML'),
      'field_presentation_body:language' => array('field' => 'idioma'),

      'field_presentation_teaser' => array('field' => 'cuerpo', 'callback' => 'buildTeaser'),
      'field_presentation_teaser:language' => array('field' => 'idioma'),

      'field_presentation_author' => array('field' => 'autor_id'),
      'field_presentation_author:language' => array('field' => 'idioma'),
      'field_id_sade' => array('field' => 'id_sade'),
      'field_id_sade_maestro' => array('field' => 'id_sade_maestro'),

      'field_country' => array('field' => 'lugar_pais_iso2'),
      'field_presentation_city' => array('field' => 'lugar_ciudad'),
      'field_presentation_city:language' => array('field' => 'idioma'),
      'field_presentation_workarea' => array('field' => 'id_division'),

    );
  }

  static public function getDefaultEquivalences() {

    return array(
      'translate' => TRUE,
      'field_presentation_body:format' => 'filtered_html',
      'field_presentation_type' => self::PRESENTATION_TYPE_SPEECH,
    );
  }

  public function getXMLFeed() {

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
      $entity->field_presentation_image = $field_image;
    }
    $files = array();
    if(isset($row->archivos)) $files = $row->archivos;
    if(count($files) > 0){
      $entity->field_presentation_files = array();
      $entity->field_presentation_files[$lng] = array();
      $i = 0;
      foreach($files as $file){
        $file->uid = $uid;
        $entity->field_presentation_files[$lng][$i++] = (array)$file;
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

    //$teaser = check_plain($currentRow->xml->bajada);
    $body   = $this->filterHTML($currentRow->xml->cuerpo);
    $teaser = text_summary($body, 'plain_text', 200);
    $title  = check_plain($currentRow->xml->titulo);
    $date   = $currentRow->xml->fecha;


    drush_print_r("nid: " . $node->nid . " -- sade_id: " . $id_sade . " -- lang: " . $idioma);

    /* Se guarda cada uno de los campos traducidos para el nodo padre */
    $this->setNodeTitle($node, $idioma, $title);
    $this->setNodeBody($node, $idioma, $body, 'field_presentation_body');
    $this->setNodeTeaser($node, $idioma, $teaser, 'field_presentation_teaser');
    $this->setNodeDate($node, $idioma, $date, 'field_presentation_date');

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



  /**
   * Se borran datos de imagenes y archivos.
   *
   * En particular los datos de imagenes tales como los archivos fisicos de las
   * imagenes cuando se pueda y las relaciones en base de datos de las imagenes
   * "managed".
   *
   * @param int $entity_id
   */
  public function prepareRollback($entity_id) {
    parent::prepareRollback($entity_id);

    $field_name = "field_presentation_image";
    $entity_type = "node";
    $base_path  = DRUPAL_ROOT;
    $base_path .= self::PRESENTATION_IMAGES_PATH;
    $entity = entity_load_single($entity_type, $entity_id);
    $this->eliminarImagenes($entity, $field_name, $base_path);
  }


}
