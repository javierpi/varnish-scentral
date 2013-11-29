<?php


class Archivos {
  protected $archivos;
  protected $type;



  public function __construct($type){
    $this->type = $type;
    $this->init();
  }



  public function init() {
    $path_module = drupal_get_path('module', 'migrar');

    $config_path = "/config/migrar.config.xml";
    $config = simplexml_load_file($path_module . $config_path);

    $path_xml = (string) $config->{$this->type}->xml_file_path;
    $archivos_raw = simplexml_load_file($path_xml);

    $archivos = array();
    foreach ($archivos_raw as $archivo_raw){

      $id_sade = (int)$archivo_raw->id_sade;

      $archivo = array(
        'URL_SADE'    => (string) $archivo_raw->URL_SADE,
        'extension'   => (string) $archivo_raw->extension,
        'NewFileName' => (string) $archivo_raw->NewFileName,
        'descripcion' => (string) $archivo_raw->descripcion,
        'idioma'      => (string) $archivo_raw->idioma,
        'tipo'        => (string) $archivo_raw->tipo,
      );

      $archivos[$id_sade][] = $archivo;
    }

    $this->archivos = $archivos;
  }



  public function getArchivosByIdSade($id_sade){
    return $this->archivos[$id_sade];
  }
}