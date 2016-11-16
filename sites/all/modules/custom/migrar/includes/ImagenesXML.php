<?php


class ImagenesXML{
  protected $imagenes;
  protected $type;
  protected $imagesService;
  protected $id_sade;
  protected $nMigracion;



  public function __construct($type, $id_sade, $nMigracion){
    $this->type = $type;
    $this->id_sade = $id_sade;
    $this->nMigracion = $nMigracion;
    $this->init();
  }



  public function init() {
    if(!isset($this->type)) {
      throw new LogicException("El type no fue declarado");
    }

    $path_module = drupal_get_path('module', 'migrar');

    $config_path = "/config/migrar.config.xml";
    $config = simplexml_load_file($path_module . $config_path);

    $this->imagesService = $config->{$this->type}->images_service;
    $imageEndPoint = (string)$this->imagesService->service_endpoint;
    $queryParams = array(
      'id_sade' => $this->id_sade,
      'num_records' => '',
      'id_migracion' => $this->nMigracion
    );

    $urlQuery = $imageEndPoint . '?' . http_build_query($queryParams, '', '&');
    $xmlImages = simplexml_load_string(file_get_contents($urlQuery));

    $sourcesPath = (string)$config->{$this->type}->source_images;

    $imagenes = array();
    foreach ($xmlImages as $xmlImage){
      $newFileName = (string) $xmlImage->NewFotoFileName;
      $fileUrl     = (string) $xmlImage->URL_SADE;
      $newFilePath = $sourcesPath . "/" . $newFileName;
      if(!file_exists($newFilePath)){
        $piecesUrl = explode("/", $fileUrl);
        foreach ($piecesUrl as $i => $pieceUrl){
          if($i<2)            continue;
          $piecesUrl[$i] = urlencode($pieceUrl);
        }
        $fileUrl = implode("/", $piecesUrl);
        file_put_contents($newFilePath, fopen(($fileUrl), 'r'));
      }
      $id_foto = (int)$xmlImage->id_foto;

      $imagenes[$this->id_sade][$id_foto] = array(
        'id_foto'  => $id_foto,
        'fileName' => (string) $xmlImage->NewFotoFileName,
        'alt'      => (string) $xmlImage->texto_alternativo,
        'title'    => (string) $xmlImage->texto_alternativo,
        'filesize' => (int)    $xmlImage->tamano_kb,
        'credito'  => (string) $xmlImage->credito,
      );
      /*
       * Se ordenan las imagenes por peso. Las mas pesadas van primero.
       */
      foreach($imagenes as $id_sade => $imagenes_type){
        usort($imagenes_type, array($this, 'ordenarImagenes'));
        $imagenes[$id_sade] = $imagenes_type;
      }

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