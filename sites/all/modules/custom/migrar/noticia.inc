<?php
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
  public function __construct() {
    $this->type = "noticia";
    $this->init();
    $this->description = t('Importar noticias desde archivo XML');

    $this->addFieldMapping('created', 'fecha');
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
    $aux = explode(" ", $current_row->xml->fecha);
    $pieces = explode("-", $aux[0]);
    $created = mktime(0, 0, 0, $pieces[1], $pieces[0], $pieces[2]);

    $current_row->fecha         = $created;
    //$current_row->field_pr_date = $created;

    $aux2 = explode(" ", $current_row->xml->fecha_actualizacion);
    $pieces2 = explode("-", $aux2[0]);
    $changed = mktime(0, 0, 0, $pieces2[1], $pieces2[0], $pieces2[2]);

    $current_row->fecha_actualizacion = $changed;

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
      'epigrafe'            => t('Fecha y hora?'),
      'fecha'               => t('created'),
      'fecha_actualizacion' => t('updated'),
      'cuerpo'              => t('body'),
      'idioma'              => t('Idioma'),
      'minisitio'           => t('url de minisitio(si existiera)'),
      'area_de_trabajo'     => t('?'),
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

    self::fileFieldUnmigrated('field_news_files', $unmgtDests);

    self::imageFieldUnmigrated('field_news_image', $unmgtDests);

    self::taxonomyFieldUnmigrated('field_news_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_news_unbis', $unmgtDests);

    $unmgtDests[] = 'field_news_country';

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

/*
  protected function getXMLFeed() {

  }
*/


  /**
   * Callback para que el contenido html del body coincida con los permitidos.
   *
   * @param string $body
   * @return string
   */
  protected function filterHTML($html){
    /*
     * @todo preguntar cual va a ser el filtro por defecto.
     */
    $html = check_markup($html, 'filtered_html');

    return $html;
  }



  protected function buildContactInfo1($nombre){
    $xml = $this->sourceValues->xml;

    $additions = array();
    if(!empty($xml->contacto_email)) {
       $additions[] = (string)$xml->contacto_email;
    }
    if(!empty($xml->contacto_fono)) {
       $additions[] = (string)$xml->contacto_fono;
    }
    array_unshift($additions, $nombre);

    return self::formatterContactInfo($additions);
  }



  protected function buildContactInfo2($nombre){
    $xml = $this->sourceValues->xml;

    $additions = array();
    if(!empty($xml->contacto_email_2)) {
       $additions[] = (string)$xml->contacto_email_2;
    }
    if(!empty($xml->contacto_fono_2)) {
       $additions[] = (string)$xml->contacto_fono_2;
    }
    array_unshift($additions, $nombre);

    return self::formatterContactInfo($additions);
  }



  protected static function formatterContactInfo($additions){
    /*
     * @todo mejorar formato
     */
    if (empty($additions)) return "";

    $output = implode("\n", $additions) ;

    return $output;
  }

}