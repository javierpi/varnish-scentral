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

    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_pr_date', 'fecha_actualizacion')
      ->xpath('fecha_actualizacion')
      ->arguments($arguments);
    //$this->addFieldMapping('created')->defaultValue(mktime(0, 0, 0, 7, 29, 1980));
    //$this->addFieldMapping('changed')->defaultValue(mktime(0, 0, 0, 7, 29, 1980));
    //$this->addFieldMapping('field_pr_date')->defaultValue(mktime(0, 0, 0, 7, 29, 1980));

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
      'epigrafe'            => t('Fecha y hora?'),
      'fecha'               => t('created'),
      'fecha_actualizacion' => t('updated'),
      'contacto_nombre'     => t('Nombre contacto 1'),
      'contacto_email'      => t('Email contacto 1'),
      'contacto_fono'       => t('Fono contacto 1'),
      'contacto_nombre_2'   => t('Nombre contacto 2'),
      'contacto_email_2'    => t('Email contacto 2'),
      'contacto_fono_2'     => t('Fono contacto 2'),
      'contacto_nombre_3'   => t('Nombre contacto 3'),
      'contacto_email_3'    => t('Email contacto 3'),
      'contacto_fono_3'     => t('Fono contacto 3'),
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

    self::fileFieldUnmigrated('field_pr_files', $unmgtDests);
    self::imageFieldUnmigrated('field_pr_image', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_pr_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_pr_unbis', $unmgtDests);

    unset($unmgtDests[array_search ( 'created' , $unmgtDests )]);
    unset($unmgtDests[array_search ( 'changed' , $unmgtDests )]);

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
      'field_pr_body'   => array('field' => 'cuerpo', 'callback' => 'filterHTML'),
      'field_pr_body:language'   => array('field' => 'idioma'),
      'field_pr_teaser' => array('field' => 'bajada', 'callback' => 'filterHTML'),
      'field_pr_teaser:language' => array('field' => 'idioma'),
      'field_pr_contact_intitutional' => array('field' => 'contacto_nombre', 'callback' => 'buildContactInfo1'),
      'field_pr_contact_person' => array('field' => 'contacto_nombre_2', 'callback' => 'buildContactInfo2'),
      'field_pr_contact_intitutional:language' => array('field' => 'idioma'),
      'field_pr_contact_person:language' => array('field' => 'idioma'),
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


/*
  protected function getXMLFeed() {

  }
*/



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