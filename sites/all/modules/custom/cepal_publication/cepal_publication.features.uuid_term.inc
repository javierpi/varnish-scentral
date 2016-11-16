<?php
/**
 * @file
 * cepal_publication.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cepal_publication_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Cuadernos estadísticos',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '020b4ccd-2ce2-4777-8b54-d9a27d72eb67',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '3cd04301-cd43-41e8-bbc8-ed15ac087290',
    ),
  );
  $terms[] = array(
    'name' => 'Copublicaciones',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => '08d88c0f-d543-4fd9-83db-d976b96f89e8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Series de la Cepal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '11812ac1-2ccc-426a-bf52-e0e80402619b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Publicaciones Institucionales',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '11accdd2-0cb6-4209-8349-69e2ffb251c7',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Documento de Trabajo',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '3025c2b8-4d9f-4fd3-bb1d-56f008c359aa',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'Otros',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '37252f61-2cf3-440e-aac8-02c75f6bb525',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'Colecciones de la Cepal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '3cd04301-cd43-41e8-bbc8-ed15ac087290',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Resolución',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '41de2185-7f2d-49e6-bba5-f52480931870',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'Declaración',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '46fa98a2-5006-41ec-a176-d73568cb9d71',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'Documentos de conferencia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => '5589088d-d3a7-40e0-816a-897959d5cda7',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Coediciones',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '6d807458-1f0b-4de9-b5fa-58255bf4f2a4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Acuerdo',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '788fc876-21ee-4401-9305-dcd2f6d5a76f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'Cuadernos de la CEPAL',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '8f42d357-34e2-4edf-812f-7168d8ed7549',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '3cd04301-cd43-41e8-bbc8-ed15ac087290',
    ),
  );
  $terms[] = array(
    'name' => 'Documento de Referencia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '977e1b5c-5b5c-4743-be0f-f904a9e0af1d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  $terms[] = array(
    'name' => 'La Hora de la Igualdad',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'a830389f-eba0-4150-9ab1-b11aae360112',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '3cd04301-cd43-41e8-bbc8-ed15ac087290',
    ),
  );
  $terms[] = array(
    'name' => 'Informes anuales / Flagship',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'b3c653bb-bd3a-4625-bda2-91c3ab34a771',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Libros de la CEPAL',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b6b64481-bf95-4606-af6f-9731b3d80576',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '3cd04301-cd43-41e8-bbc8-ed15ac087290',
    ),
  );
  $terms[] = array(
    'name' => 'Documentos de proyecto',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => 'c4dc39a6-993b-4a71-b50b-9f305e6f85ad',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
  );
  $terms[] = array(
    'name' => 'Documento de posición',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'f9b77a71-84cd-49a1-8015-dd34d729ade2',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'publication_type',
    'parent' => array(
      0 => '5589088d-d3a7-40e0-816a-897959d5cda7',
    ),
  );
  return $terms;
}
