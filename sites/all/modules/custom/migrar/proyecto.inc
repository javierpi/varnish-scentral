<?php

class ProyectoXMLMigration extends XMLMigration {

  
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Importar proyectos desde archivo XML');
    //$this->dependencies = array('cepal_base');

    $fields = $this->getXMLFields();

    $this->map = new MigrateSQLMap($this->machineName, array(
      'sourceid' => array(
        'type' => 'varchar',
        'length' => 4,
        'not null' => TRUE,
      )
      ), MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrar') . '/xml/';
    $items_url = $xml_folder . '0001.xml';
    $item_xpath = '/GetProyectos/proyecto';  

    $item_ID_xpath = 'id_protrack';       

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    
    $this->destination = new MigrateDestinationNode('cepal_project');

    $normalEquivalences = $this->getNormalEquivalences();
    $defaultEquivalences = $this->getDefaultEquivalences();
    $this->normalFieldMapping($normalEquivalences);
    $this->defaultFieldMapping($defaultEquivalences);

    $arguments = DateMigrateFieldHandler::arguments('America/Santiago');
    $this->addFieldMapping('field_project_date_finish', 'fecha_fin')
      ->xpath('fecha_fin')
      ->arguments($arguments);
    
    $this->addFieldMapping('field_project_date', 'fecha_aprobacion');

    $this->addFieldMapping('field_project_expected_results', 'resultados');
    $this->addFieldMapping('field_project_objectives', 'objetivos');
    
    $this->addUnmigratedDestinations($this->getUnmigratedDestinations());
  }
  
  
  public function prepareRow($current_row) {
   /**
     * @todo revisar timezone
     */
    $date_data = array(
      'from' => (string) $current_row->xml->fecha_aprobacion,
      'to'   => (string) $current_row->xml->fecha_fin_estimada,
    );
    
    $current_row->fecha_aprobacion = drupal_json_encode($date_data);
    
    
    $current_row->resultados = array();
    foreach($current_row->xml->resultados->resultado as $resultado){
      $current_row->resultados[] = $resultado->descripcion;
    }
    
    $current_row->objetivos = array();
    foreach($current_row->xml->objetivos->objetivo as $objetivo){
      $current_row->objetivos[] = $objetivo->descripcion;
    }
    
    return true;
    
  }


  
  private function normalFieldMapping($map) {
    foreach ($map as $source => $destination) {
      if ($destination['field'] !== false) {
        $this->addFieldMapping($destination['field'], $source)
          ->xpath($source)
        ;
        if (strlen($destination['callback']) > 0) {
          $fields = $this->getFieldMappings();
          $fields[$destination['field']]->callbacks(array($this, $destination['callback']));
        }
      }
    }
  }



  private function defaultFieldMapping($map) {

    foreach ($map as $destination => $value) {
      $this->addFieldMapping($destination)
        ->defaultValue($value);
    }
  }



  static private function getXMLFields() {
    return array(
      'id_protrack' => t('ID from ProTrack'),
      'titulo' => t('Title'),
      'titulo_corto' => t('Short Title'),
      'body' => t('Project description'),
      'simbolo' => t('Symbol'),
      'estado' => t('Project\'s state'),
      'contacto' => t('Contact'),
      'tipo_proyecto' => t('Project\'s type'),
      'presupuesto' => t('Budget'),
      'fecha_aprobacion' => t('approval date'),
      'fecha_fin_estimada' => t('Estimated end date'),
      'fecha_fin' => t('End date'),
      'duracion_meses' => t('Project\'s time scope'),
      'division' => t('Division'),
      'division_id' => t('Division ID'),
      'subprograma' => t('Subprogram'),
      'donante' => t('Donor'),
    );
  }



  static private function getUnmigratedDestinations() {
    return array(
      'revision_uid',
      'uid',
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'is_new',
      'field_project_abstract:format',
      'field_project_abstract:language',
      'comment',
      'field_project_area_ref'
    );
  }



  static public function getNormalEquivalences() {
    return array(
      'id_protrack' => array('field' => false, 'callback' => ''),
      'titulo' => array('field' => 'title', 'callback' => ''),
      'titulo_corto' => array('field' => 'field_project_short_title', 'callback' => ''),
      'body' => array('field' => 'field_project_abstract', 'callback' => ''),
      'simbolo' => array('field' => false, 'callback' => ''),
      'estado' => array('field' => false, 'callback' => ''),
      'contacto' => array('field' => false, 'callback' => ''),
      //'tipo_proyecto' => array('field' => false, 'callback' => ''),
      'presupuesto' => array('field' => 'field_project_budget', 'callback' => ''),
      'duracion_meses' => array('field' => false, 'callback' => ''),
      'division' => array('field' => false, 'callback' => ''),
      'division_id' => array('field' => false, 'callback' => ''),
      'subprograma' => array('field' => false, 'callback' => ''),
      'donante' => array('field' => 'field_project_donor', 'callback' => ''),
      'simbolo' => array('field' => 'field_project_code', 'callback' => ''),
      'contacto' => array('field' => 'field_project_contact_person', 'callback' => ''),
      'division_id' => array('field' => 'field_project_division', 'callback' => ''),
      //'resultados' => array('field' => 'field_project_expected_results', 'callback' => ''),
      //'estado' => array('field' => 'field_project_code', 'callback' => 'estadoCallback'),
    );
  }

  
  
  static public function getDefaultEquivalences() {
    return array(
      'translate' => true,
    );
  }
  
  /**
   * Formatter Callbacks
   */
  protected function expectedResultsCallback($value) {
   $value .= "resultado";
  }
  
  
}