<?php
/**
 * @file
 * Este archivo define la clase que migra articulos
 *
 * La clase se basa en BaseMigracion e implementa BaseMigracionInterface.
 * BaseMigracion extiende desde el framework que provee el modulo migrate.
 */
class ArticuloXMLMigration extends BaseMigracion implements BaseMigracionInterface {


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
    $aux = explode(" ", $current_row->xml->fecha);
    $pieces = explode("-", $aux[0]);
    $created = mktime(0, 0, 0, $pieces[1], $pieces[0], $pieces[2]);

    $current_row->fecha = $created;

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


}