<?php
/**
 * @file
 * Este archivo define la clase que migra proyectos
 *
 * La clase se basa en BaseMigracion e implementa BaseMigracionInterface.
 * BaseMigracion extiende desde el framework que provee el modulo migrate.
 */
class ProyectoXMLMigration extends BaseMigracion implements BaseMigracionInterface {


  /**
  * Constructor sin parametros.
  */
  public function __construct() {
    $this->type = "proyecto";
    $this->init();
    $this->description = t('Importar proyectos desde archivo XML');


    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_project_date_finish', 'fecha_fin')
      ->xpath('fecha_fin')
      ->arguments($arguments);

    /* Datos de fechas o campos multiples. Este tipo de campos usan la funcion
     * prepareRow() para hacer su migracion.
     *
     * @see prepareRow()
     */
    $this->addFieldMapping('field_project_date', 'fecha_aprobacion');
    $this->addFieldMapping('field_project_expected_results', 'resultados');
    $this->addFieldMapping('field_project_objectives', 'objetivos');
    $this->addFieldMapping('field_project_country', 'countries');
    $this->addFieldMapping('field_project_outputs_planned', 'outputs');

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
    /*
     * @todo revisar timezone
     */
    $date_data = array(
      'from' => (string) $current_row->xml->fecha_aprobacion,
      'to'   => (string) $current_row->xml->fecha_fin_estimada,
    );

    $current_row->fecha_aprobacion = drupal_json_encode($date_data);

    $current_row->resultados = array();
    foreach ($current_row->xml->resultados->resultado as $resultado) {
      $current_row->resultados[] = $resultado->descripcion;
    }

    $current_row->objetivos = array();
    foreach ($current_row->xml->objetivos->objetivo as $objetivo) {
      $current_row->objetivos[] = $objetivo->descripcion;
    }

    $current_row->outputs = array();
    foreach ($current_row->xml->outputs->output as $output) {
      $current_row->outputs[] = $output->descripcion;
    }

    $current_row->countries = array();
    if (!empty($current_row->xml->countries->country)) {
      foreach ($current_row->xml->countries->country as $country) {
        $iso3 = (string)$country->id_country;
        $country_id = $this->getCountryIdByISO3($iso3);
        $current_row->countries[] = $country_id;
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
      'id_protrack'        => t('ID from ProTrack'),
      'titulo'             => t('Title'),
      'titulo_corto'       => t('Short Title'),
      'body'               => t('Project description'),
      'simbolo'            => t('Symbol'),
      /* Se envia el nombre del estado, pero tenemos el id normalizado */
      //'estado'             => t('Project\'s state'),
      'contacto'           => t('Contact'),
      'tipo_proyecto'      => t('Project\'s type'),
      'presupuesto'        => t('Budget'),
      'fecha_aprobacion'   => t('approval date'),
      /* La fecha de fin estimada va como fecha de fin en el campo aprobacion */
      //'fecha_fin_estimada' => t('Estimated end date'),
      'fecha_fin'          => t('End date'),
      'duracion_meses'     => t('Project\'s time scope'),
      'division'           => t('Division'),
      'division_id'        => t('Division ID'),
      'subprograma'        => t('Subprogram'),
      'donante'            => t('Donor'),
      'countries'          => t('Countries related to the project'),
      'terminosUNBIS'      => t('Cross-site vocabulary'),
      'idioma'             => t('Language'),
      'idioma_original'    => t('Original language'),
      'id_estado'          => t('State\'s id'),
      'url_proyecto'       => t('Project\'s url'),
      'subprograma'        => t('Subprogram'),
      /* El donante esta como texto en el tipo de contenido por lo que no se usa
       * el id
       */
      'id_donante'         => t('Donor\'s id'),
      'objetivos'          => t('Objectives'),
      'resultados'         => t('Results'),
      'outputs'            => t('Expected Outputs'),
      'productosSADE'      => t('Related content from SADE'),
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

    $unmgtDests[] = 'field_project_abstract:format';
    $unmgtDests[] = 'field_project_abstract:language';

    $unmgtDests[] = 'field_project_area_ref';

    /* @todo las referencias deberian ser migradas en una segunda etapa */
    $unmgtDests[] = 'field_project_referece';

    self::fileFieldUnmigrated('field_project_files', $unmgtDests);

    $unmgtDests[] = 'field_project_code:language';
    $unmgtDests[] = 'field_project_contact_person:language';
    $unmgtDests[] = 'field_project_donor:language';
    $unmgtDests[] = 'field_project_expected_results:language';
    $unmgtDests[] = 'field_project_outputs_planned:language';
    $unmgtDests[] = 'field_project_short_title:language';
    $unmgtDests[] = 'field_project_objectives:language';

    self::imageFieldUnmigrated('field_project_image', $unmgtDests);

    /*
     * @todo revisar inconsistencia de cardinalidad source-destination para link
     */
    self::urlFieldUnmigrated('field_project_link', $unmgtDests);

    self::taxonomyFieldUnmigrated('field_project_special_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_project_topic', $unmgtDests);
    self::taxonomyFieldUnmigrated('field_project_unbis', $unmgtDests);

    $unmgtDests[] = 'field_project_url:title';
    $unmgtDests[] = 'field_project_url:attributes';
    $unmgtDests[] = 'field_project_url:language';

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
      /* No existe el campo en el tipo de contenido proyecto */
      'duracion_meses' => array('field' => FALSE, 'callback' => ''),

      /* Se usa el id_division */
      'division'       => array('field' => FALSE),

      /* No existe el campo en el tipo de contenido proyecto */
      'subprograma'    => array('field' => FALSE),

      /* se usa el id del estado */
      'estado'         => array('field' => FALSE),

      /*
       * El campo es field_project_unbis
       * No se han importado aun los terminos
       *
       * @todo agregar unbis cuando los terminos hayan sido importados.
       */
      'terminosUNBIS'  => array('field' => FALSE),

      /* El campo "titulo" puede tener mas de 255 caracteres */
      'field_project_short_title'         => array('field' => 'titulo'),
      'title'   => array('field' => 'titulo_corto'),
      'field_project_abstract'           => array('field' => 'body'),
      'field_project_budget'    => array('field' => 'presupuesto'),
      'field_project_donor'        => array('field' => 'donante'),
      'field_project_code'        => array('field' => 'simbolo'),
      'field_project_contact_person'       => array('field' => 'contacto'),
      /* @todo reemplazar despues con la referencia a la entidad Division. */
      'field_project_division'    => array('field' => 'fdivision_id'),
      'field_project_protrack_id'    => array('field' => 'id_protrack'),
      'field_project_status'      => array('field' => 'id_estado'),
      'field_project_financing'  => array('field' => 'tipo_proyecto'),
      'field_project_url'   => array('field' => 'url_proyecto'),
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
    );
  }

}