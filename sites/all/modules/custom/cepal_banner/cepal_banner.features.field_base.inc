<?php
/**
 * @file
 * cepal_banner.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cepal_banner_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_banner_behavior'
  $field_bases['field_banner_behavior'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_behavior',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Slide Home',
        2 => 'Promotion',
        3 => 'Top Page',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_banner_destination_type'
  $field_bases['field_banner_destination_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_destination_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Internal',
        2 => 'External',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_banner_image_main_slide'
  $field_bases['field_banner_image_main_slide'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_image_main_slide',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_banner_image_promotion'
  $field_bases['field_banner_image_promotion'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_image_promotion',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_banner_image_top_page'
  $field_bases['field_banner_image_top_page'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_image_top_page',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_banner_link'
  $field_bases['field_banner_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_link',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_banner_observatories'
  $field_bases['field_banner_observatories'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_observatories',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'OFILAC',
        2 => 'RISALC',
        3 => 'OIG',
        4 => 'ASIA-PACIFICO',
        5 => 'BANDA ANCHA',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_banner_related_content'
  $field_bases['field_banner_related_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_related_content',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'cepal_article' => 'cepal_article',
          'cepal_event' => 'cepal_event',
          'cepal_graphic_info' => 'cepal_graphic_info',
          'cepal_news' => 'cepal_news',
          'cepal_page' => 'cepal_page',
          'cepal_pr' => 'cepal_pr',
          'cepal_presentation' => 'cepal_presentation',
          'cepal_project' => 'cepal_project',
          'cepal_publication' => 'cepal_publication',
          'cepal_speech' => 'cepal_speech',
          'session' => 'session',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_banner_short_text'
  $field_bases['field_banner_short_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_short_text',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_banner_subsidiary_bodies'
  $field_bases['field_banner_subsidiary_bodies'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_subsidiary_bodies',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Comité Plenario',
        2 => 'Conferencia Estadística de las Américas',
        3 => 'Conferencia Regional sobre la mujer de América Latina y el Caribe',
        4 => 'Comité de Desarrollo y Cooperación del Caribe',
        5 => 'Conferencia Regional sobre Población y Desarrollo de ALC',
        6 => 'Consejo Regional de Planificación',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_banner_workarea'
  $field_bases['field_banner_workarea'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_workarea',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Economic Development - División de Desarrollo Económico',
        2 => 'Social Development - División de Desarrollo Social',
        3 => 'Statistics - División de Estadísticas',
        4 => 'CELADE-Population Division - CELADE - División de Población',
        5 => 'International Trade and Integration - División de Comercio Internacional e Integración',
        6 => 'Economic and Social Planning (ILPES) - Instituto Latinoamericano y del Caribe de Planificación Económica y Social (ILPES)',
        7 => 'Production, Productivity and Management - División de Desarrollo Productivo y Empresarial',
        8 => 'Sustainable Development and Human Settlements - División de Desarrollo Sostenible y Asentamientos Humanos',
        9 => 'Natural Resources and Infrastructure  - División de Recursos Naturales e Infraestructura',
        10 => 'Gender Affairs - División de Asuntos de Género',
        11 => 'Financing for Development - División de Financiamiento para el Desarrollo',
        12 => 'ECLAC Subregional Headquarters in Mexico, Mexico, D.F. - Sede Subregional de la CEPAL en México - México, D.F.',
        13 => 'ECLAC Subregional Headquarters for the Caribbean, Port of Spain, Trinidad and Tobago - Sede Subregional de la CEPAL para el Caribe - Puerto España',
        14 => 'ECLAC Office in Bogota - Oficina de la CEPAL en Bogotá',
        15 => 'ECLAC Office in Brasilia - Oficina de la CEPAL en Brasilia',
        16 => 'ECLAC Office in Buenos Aires - Oficina de la CEPAL en Buenos Aires',
        17 => 'ECLAC Office in Montevideo - Oficina de la CEPAL en Montevideo',
        18 => 'ECLAC Office in Washington, D.C. - Oficina de la CEPAL en Washington',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
