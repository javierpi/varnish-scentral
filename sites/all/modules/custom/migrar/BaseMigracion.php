<?php

/**
 * @file
 * Este archivo contiene la clase BaseMigracion.
 *
 * La clase BaseMigracion se deberia usar para las migraciones que se hagan
 * de los tipos de contenidos del proyecto CEPAL.
 */

/**
 * Provee una base para la migracion de tipos de contenido.
 *
 * Se basa en el framework provisto por el modulo Migrate.
 */
abstract class BaseMigracion extends XMLMigration {

  /**
   * Atributo que debe contener la configuracion obtenida desde xml.
   *
   * @var mixed
   */
  protected $config;

  /**
   * El tipo (interno) que se esta migrando.
   *
   * Es independiente del tipo de contenido de la migracion, sino solo tiene
   * sentido durante la migracion. Un ejemplo seria "proyecto".
   *
   * @var string
   */
  protected $type;



  /**
   * Inicializa la variable $config dado un objeto que ya tiene definido $type.
   *
   * Si el objeto no tiene definido path entonces levanta una excepcion.
   */
  protected function init() {
    /* Si no se define el atributo type, lanza una excepcion */
    if (is_null($this->type)) {
      $msje = "El valor del atributo type debe estar definido";
      throw new UnexpectedValueException($msje);
    }
    parent::__construct();
    $path_module = drupal_get_path('module', 'migrar');

    $config_path = "/config/migrar.config.xml";
    $config = simplexml_load_file($path_module . $config_path);

    $this->config = $config;

    $fields = $this->getXMLFields();

    $this->map = new MigrateSQLMap($this->machineName, array(
      'sourceid' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
      )
      ), MigrateDestinationNode::getKeySchema()
    );

    /* Se actualiza el archivo xml con la info de los objetos a migrar */
    $this->getXMLFeed();

    $items_url = $this->getXMLFilePath();
    $item_xpath = $this->getXPath();

    $item_ID_xpath = $this->getXPathId();
    $destination_node = $this->getDestinationNode();

    $items_class  = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode($destination_node);

    $normalEquivalences = $this->getNormalEquivalences();
    $defaultEquivalences = $this->getDefaultEquivalences();
    $this->normalFieldMapping($normalEquivalences);
    $this->defaultFieldMapping($defaultEquivalences);
    $this->addUnmigratedDestinations($this->getUnmigratedDestinations());
  }



  /**
   * Setea la variable type
   *
   * @param string $type
   *  - Debe coincidir con el tipo definido en el xml.
   * @return \BaseMigracion
   */
  protected function setType($type) {
    $this->type = $type;

    return $this;
  }



  /**
   * Refresca el archivo XML que contiene los datos a migrar.
   *
   * La funcion llama al webservice correspondiente y reemplaza el archivo con
   * datos de migracion por otro de origen inmediato.
   */
  protected function getXMLFeed() {
    $url = $this->getWebServiceQuery();

    $xml = file_get_contents($url);
    $file_path = $this->getXMLFilePath();

    if (file_exists($file_path)) {
      /*
       * @todo Descomentar el unlink.
       */
      //unlink($file_path);
    }

    $file = fopen($file_path, "wb");
    fwrite($file, $xml);
    fclose($file);
  }



  /**
   * Retorna un arreglo con los nombres de los campos que no son migrados.
   *
   * Los hijos deberian usar la implementacion del padre y sumar a eso los
   * campos propios.
   *
   * @return array
   */
  static protected function getUnmigratedDestinations() {
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
      'comment',
      'path',
    );
  }



  /**
   * Hace la importacion de un campo cuando la correspondencia es 1-1
   *
   * @param array $map
   */
  protected function normalFieldMapping($map) {

    foreach ($map as $source => $destination) {
      if ($destination['field'] !== FALSE) {
        $field = $destination['field'];
        $this->addFieldMapping($source, $field)
          ->xpath($field)
        ;
        if(isset($destination['callback'])){
          $callback_not_empty = (strlen($destination['callback']) > 0);
        }
        else{
          $callback_not_empty = false;
        }
        if ($callback_not_empty ) {
          $fields =& $this->fieldMappings;
          $callback_args = array($this, $destination['callback']);
          $fields[$source]->callbacks($callback_args);
        }
      }
    }
  }



  /**
   * Agrega valores para las equivalencias que tienen valor fijo.
   *
   * @param $map
   */
  protected function defaultFieldMapping($map) {
    foreach ($map as $destination => $value) {
      $this->addFieldMapping($destination)
        ->defaultValue($value);
    }
  }



  /**
   * Devuelve el string de la url del webservice que se debe consultar.
   *
   * @return string
   */
  protected function getWebServiceQuery() {
    $type = $this->type;
    $endpoint = $this->config->{$type}->service_endpoint;

    $query_params = array();
    $service_params =
    $this
      ->config
      ->{$type}
      ->service_parameters
      ->service_parameter
    ;

    foreach ($service_params as $parameter) {
      $query_params[(string)$parameter[0]->name] = (string)$parameter->value;
    }
    $query_str = http_build_query($query_params, '', '&');

    $url = $endpoint . "?" . $query_str;

    return $url;
  }



  /**
   * Devuelve el string del path del archivo xml con informacion a migrar.
   *
   * @return string
   */
  protected function getXMLFilePath() {
    $type = $this->type;
    return $this->config->{$type}->xml_file_path;
  }



  /**
   * Devuelve el string que corresponde al xpath del archivo xml.
   *
   * @return string
   */
  protected function getXPath() {
    $type = $this->type;
    return $this->config->{$type}->x_path;
  }



  /**
   * Devuelve el string que corresponde al id del xpath del archivo xml.
   *
   * @return string
   */
  protected function getXPathId() {
    return (string)$this->config->{$this->type}->id_x_path;
  }



  /**
   * Devuelve el nombre de maquina del destino de la migracion.
   *
   * @return string
   */
  protected function getDestinationNode() {
    return (string)$this->config->{$this->type}->destination_node;
  }



  /**
   * Dado un codigo iso3 de pais, devuelve el identificador iso2.
   *
   * @param string $iso3
   *   - Codigo de pais de formato iso3.
   * @return string
   *   - Codigo de pais de formato iso2 que es llave de Entity Country.
   */
  public static function getCountryIdByISO3($iso3) {
    $country = countries_country_lookup($iso3, "iso3");
    if (!$country) return 0;
    return $country->identifier();
  }



  /**
   * Agrega a un arreglo las variables sin migrar de un campo de imagen.
   *
   * @param string $field_name
   *   - Nombre del campo imagen que se quiere dejar migrado con valores por
   *   defecto
   * @param array $unmigratedDest
   *   - Arreglo que tiene los valores de los campos a migrar con valores por
   *   defecto
   */
  public static function imageFieldUnmigrated($field_name, &$unmigratedDest) {
    $unmigratedDest[] = $field_name;
    $unmigratedDest[] = $field_name . ':file_class';
    $unmigratedDest[] = $field_name . ':language';
    $unmigratedDest[] = $field_name . ':destination_dir';
    $unmigratedDest[] = $field_name . ':destination_file';
    $unmigratedDest[] = $field_name . ':file_replace';
    $unmigratedDest[] = $field_name . ':preserve_files';
    $unmigratedDest[] = $field_name . ':source_dir';
    $unmigratedDest[] = $field_name . ':alt';
    $unmigratedDest[] = $field_name . ':title';
  }



  /**
   * Agrega a un arreglo las variables sin migrar de un campo de taxonomia.
   *
   * @param string $field_name
   *   - Nombre del campo taxonomia que se quiere dejar migrado con valores por
   *   defecto
   * @param array $unmigratedDest
   *   - Arreglo que tiene los valores de los campos a migrar con valores por
   *   defecto
   */
  public static function taxonomyFieldUnmigrated($field_name, &$unDest) {
    $unDest[] = $field_name;
    //$unDest[] = $field_name . ':language';
    $unDest[] = $field_name . ':source_type';
    $unDest[] = $field_name . ':create_term';
    $unDest[] = $field_name . ':ignore_case';
  }



  /**
   * Agrega a un arreglo las variables sin migrar de un campo de archivo.
   *
   * @param string $field_name
   *   - Nombre del campo archivo que se quiere dejar migrado con valores por
   *   defecto
   * @param array $unmigratedDest
   *   - Arreglo que tiene los valores de los campos a migrar con valores por
   *   defecto
   */
  public static function fileFieldUnmigrated($field_name, &$unmigratedDest) {
    $unmigratedDest[] = $field_name;
    $unmigratedDest[] = $field_name . ':file_class';
    $unmigratedDest[] = $field_name . ':language';
    $unmigratedDest[] = $field_name . ':destination_dir';
    $unmigratedDest[] = $field_name . ':destination_file';
    $unmigratedDest[] = $field_name . ':file_replace';
    $unmigratedDest[] = $field_name . ':preserve_files';
    $unmigratedDest[] = $field_name . ':source_dir';
    $unmigratedDest[] = $field_name . ':description';
    $unmigratedDest[] = $field_name . ':display';
  }



  /**
   * Agrega a un arreglo las variables sin migrar de un campo de url.
   *
   * @param string $field_name
   *   - Nombre del campo url que se quiere dejar migrado con valores por
   *   defecto
   * @param array $unmigratedDest
   *   - Arreglo que tiene los valores de los campos a migrar con valores por
   *   defecto
   */
  public static function urlFieldUnmigrated($field_name, &$unmigratedDest) {
    $unmigratedDest[] = $field_name;
    $unmigratedDest[] = $field_name . ':title';
    $unmigratedDest[] = $field_name . ':attributes';
    $unmigratedDest[] = $field_name . ':language';
  }


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
}