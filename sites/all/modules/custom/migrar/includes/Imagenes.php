<?php


class Imagenes{
  protected $imagenes;
  protected $type;



  public function __construct($type){
    $this->type = $type;
    $this->init();
  }



  public function init() {
    if(!isset($this->type)) {
      throw new LogicException("El type no fue declarado");
    }


    $path_module = drupal_get_path('module', 'migrar');

    $config_path = "/config/migrar.config.xml";
    $config = simplexml_load_file($path_module . $config_path);

    $path_xml = (string) $config->{$this->type}->xml_file_path;
    $imagenes_raw = simplexml_load_file($path_xml);

    $imagenes = array();
    foreach ($imagenes_raw as $imagen_raw){

      $id_sade = (int)$imagen_raw->id_sade;
      $id_foto = (int)$imagen_raw->id_foto;

      $imagenes[$id_sade][$id_foto] = array(
        'id_foto'  => $id_foto,
        'fileName' => (string) $imagen_raw->NewFotoFileName,
        'alt'      => (string) $imagen_raw->texto_alternativo,
        'title'    => (string) $imagen_raw->texto_alternativo,
        'filesize' => (int)    $imagen_raw->tamano_kb,
        'credito'  => (string) $imagen_raw->credito,
      );
    }

    /*
     * Se ordenan las imagenes por peso. Las mas pesadas van primero.
     */
    foreach($imagenes as $id_sade => $imagenes_type){
      usort($imagenes_type, array($this, 'ordenarImagenes'));
      $imagenes[$id_sade] = $imagenes_type;
    }

    $this->imagenes = $imagenes;
  }



  public function getImagenesByIdSade($id_sade){
    if(!is_int($id_sade)){
      throw new InvalidArgumentException("El id_sade debe ser un numero entero y se ha entregado". $id_sade);
    }
    if(!isset($this->imagenes[$id_sade])) return array();
    return $this->imagenes[$id_sade];
  }



  public function getImagenes(){
    return $this->imagenes;
  }



  protected function ordenarImagenes($a, $b){
    return ($a['filesize'] >= $b['filesize']) ? -1 : 1;
  }
}