<?php


class ArchivosXML{
  protected $type;
  protected $id_sade;
  protected $filesService;
  protected $archivos;
  protected $nMigracion;

  public function __construct($type, $id_sade, $nMigracion) {
    $this->type = $type;
    $this->id_sade = $id_sade;
    $this->nMigracion = $nMigracion;
    $this->init();
  }

  protected function init(){
    $path_module = drupal_get_path('module', 'migrar');

    $config_path = "/config/migrar.config.xml";
    $config = simplexml_load_file($path_module . $config_path);

    $this->filesService = $config->{$this->type}->files_service;
    $archivoEndPoint = (string)$this->filesService->service_endpoint;
    $queryParams = array(
      'id_sade' => $this->id_sade,
      'num_records' => '',
      'id_migracion' => $this->nMigracion,
    );

    $urlQuery = $archivoEndPoint . '?' . http_build_query($queryParams, '', '&');
    $xmlFiles = simplexml_load_string(file_get_contents($urlQuery));

    $sourcesPath = (string)$config->{$this->type}->source_files;

    $archivos = array();
    foreach ($xmlFiles as $xmlFile){
      $newFileName = (string) $xmlFile->NewFileName;
      $fileUrl     = (string) $xmlFile->URL_SADE;
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

      $archivo = array(
        'URL_SADE'    => (string) $xmlFile->URL_SADE,
        'extension'   => (string) $xmlFile->extension,
        'NewFileName' => (string) $xmlFile->NewFileName,
        'descripcion' => (string) $xmlFile->descripcion,
        'idioma'      => (string) $xmlFile->idioma,
        'tipo'        => (string) $xmlFile->tipo,
      );

      $archivos[$this->id_sade][] = $archivo;
    }

    $this->archivos = $archivos;
  }

  public function getArchivosByIdSade($id_sade){
    if(!isset($this->archivos[$id_sade])) return array();
    return $this->archivos[$id_sade];
  }


}