<?php
/**
 * @file
 * cepal_news.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cepal_news_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cepal_news-field_id_sade'
  $field_instances['node-cepal_news-field_id_sade'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Migration field.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_id_sade',
    'label' => 'ID SADE',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_area_ref'
  $field_instances['node-cepal_news-field_news_area_ref'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Seleccione el área de origen de la noticia.
TEMPORAL, debe ser reemplazado con una referencia a otra entidad.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_area_ref',
    'label' => 'Area',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_body'
  $field_instances['node-cepal_news-field_news_body'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insert the body text for this content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_country'
  $field_instances['node-cepal_news-field_news_country'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select a country asociated with this content.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'countries',
        'settings' => array(),
        'type' => 'country_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_country',
    'label' => 'Country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'countries',
      'settings' => array(),
      'type' => 'countries_continent',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_files'
  $field_instances['node-cepal_news-field_news_files'] = array(
    'bundle' => 'cepal_news',
    'deleted' => 0,
    'description' => 'Is possible to add attached files files to this content as a complement.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'news/files',
      'file_extensions' => 'pdf doc docx odt ppt pptx xls xlsx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_image'
  $field_instances['node-cepal_news-field_news_image'] = array(
    'bundle' => 'cepal_news',
    'deleted' => 0,
    'description' => 'Select a image asociated to this <em>New</em>. This image could be showed in the press releases lists and front pages.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_image',
    'label' => 'Imagen',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'news/images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_teaser'
  $field_instances['node-cepal_news-field_news_teaser'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insert a teaser text for this content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_teaser',
    'label' => 'Teaser',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_topic'
  $field_instances['node-cepal_news-field_news_topic'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select associated topics for this content.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_topic',
    'label' => 'Topic',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_type'
  $field_instances['node-cepal_news-field_news_type'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the <em>News type</em> to add.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_type',
    'label' => 'Type',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-cepal_news-field_news_unbis'
  $field_instances['node-cepal_news-field_news_unbis'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select an UNBIS classification for this content.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_unbis',
    'label' => 'UNBIS',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-cepal_news-title_field'
  $field_instances['node-cepal_news-title_field'] = array(
    'bundle' => 'cepal_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 'entity',
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Area');
  t('Body');
  t('Country');
  t('Files');
  t('ID SADE');
  t('Imagen');
  t('Insert a teaser text for this content.');
  t('Insert the body text for this content.');
  t('Is possible to add attached files files to this content as a complement.');
  t('Migration field.');
  t('Seleccione el área de origen de la noticia.
TEMPORAL, debe ser reemplazado con una referencia a otra entidad.');
  t('Select a country asociated with this content.');
  t('Select a image asociated to this <em>New</em>. This image could be showed in the press releases lists and front pages.');
  t('Select an UNBIS classification for this content.');
  t('Select associated topics for this content.');
  t('Select the <em>News type</em> to add.');
  t('Teaser');
  t('Title');
  t('Topic');
  t('Type');
  t('UNBIS');

  return $field_instances;
}
