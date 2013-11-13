<?php

class ImagenesComunicado {
  protected $imagenes;



  public function __construct() {
    /*
     * @todo esta ruta deberia estar en un archivo de configuracion dentro del
     * modulo.
     */
    $path_xml = "/home/francort/xml/imagenes_comunicado.xml";
    $imagenes_raw = simplexml_load_file($path_xml);

    $imagenes = array();
    foreach ($imagenes_raw as $imagen_raw){

      $id_sade = (int)$imagen_raw->id_sade;
      $id_foto = (int)$imagen_raw->id_foto;

      $imagenes[$id_sade][$id_foto] = array(
        'id_foto'  => (int) $imagen_raw->id_foto,
        'fileName' => (string) $imagen_raw->NewFotoFileName,
        'alt'      => (string) $imagen_raw->texto_alternativo,
        'title'    => (string) $imagen_raw->texto_alternativo,
        'filesize' => (int) $imagen_raw->tamano_kb,
        'credito'  => (int) $imagen_raw->credito,
      );
    }

    /*
     * Se ordenan las imagenes por peso. Las mas pesadas van primero.
     */
    foreach($imagenes as $id_sade => $imagenes_publicacion){
      usort($imagenes_publicacion, array($this, 'ordenarImagenes'));
      $imagenes[$id_sade] = $imagenes_publicacion;
    }

    $this->imagenes = $imagenes;
  }



  private function ordenarImagenes($a, $b){
    return ($a['filesize'] >= $b['filesize']) ? -1 : 1;
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

}