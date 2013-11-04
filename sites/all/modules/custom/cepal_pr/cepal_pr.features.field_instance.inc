<?php
/**
 * @file
 * cepal_pr.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cepal_pr_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cepal_pr-field_id_sade'
  $field_instances['node-cepal_pr-field_id_sade'] = array(
    'bundle' => 'cepal_pr',
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
        'weight' => 11,
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_body'
  $field_instances['node-cepal_pr-field_pr_body'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insert the body text for this <em>Press Release</em>.',
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
    'field_name' => 'field_pr_body',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_contact_intitutional'
  $field_instances['node-cepal_pr-field_pr_contact_intitutional'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'TEMPORAL, Institutional contact data.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_pr_contact_intitutional',
    'label' => 'Contact Institutional',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_contact_person'
  $field_instances['node-cepal_pr-field_pr_contact_person'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'TEMPORAL, contact details.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_pr_contact_person',
    'label' => 'Contact Person',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_country'
  $field_instances['node-cepal_pr-field_pr_country'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select a country asociated with this press release.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'countries',
        'settings' => array(),
        'type' => 'country_default',
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
    'field_name' => 'field_pr_country',
    'label' => 'Country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_date'
  $field_instances['node-cepal_pr-field_pr_date'] = array(
    'bundle' => 'cepal_pr',
    'deleted' => 0,
    'description' => 'Select the date and time of publication for this <em>Press Release</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
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
    'field_name' => 'field_pr_date',
    'label' => 'Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_files'
  $field_instances['node-cepal_pr-field_pr_files'] = array(
    'bundle' => 'cepal_pr',
    'deleted' => 0,
    'description' => 'Is possible to add attached files files to this <em>Press Release</em>.',
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
    'field_name' => 'field_pr_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'pr/files',
      'file_extensions' => 'pdf doc docx odt ppt pptx xls xlsx epub mobi',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_image'
  $field_instances['node-cepal_pr-field_pr_image'] = array(
    'bundle' => 'cepal_pr',
    'deleted' => 0,
    'description' => 'Select a image asociated to this <em>Press Releases</em>. This image could be showed in the press releases lists and front pages.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_pr_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'pr/images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_teaser'
  $field_instances['node-cepal_pr-field_pr_teaser'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insert a teaser for this <em>press release</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    'field_name' => 'field_pr_teaser',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_topic'
  $field_instances['node-cepal_pr-field_pr_topic'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select associated topics for this <em>Press Release</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
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
    'field_name' => 'field_pr_topic',
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
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-cepal_pr-field_pr_unbis'
  $field_instances['node-cepal_pr-field_pr_unbis'] = array(
    'bundle' => 'cepal_pr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select an UNBIS classification for this <em>Press Release</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
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
    'field_name' => 'field_pr_unbis',
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
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Contact Institutional');
  t('Contact Person');
  t('Country');
  t('Date');
  t('Files');
  t('ID SADE');
  t('Image');
  t('Insert a teaser for this <em>press release</em>');
  t('Insert the body text for this <em>Press Release</em>.');
  t('Is possible to add attached files files to this <em>Press Release</em>.');
  t('Migration field.');
  t('Select a country asociated with this press release.');
  t('Select a image asociated to this <em>Press Releases</em>. This image could be showed in the press releases lists and front pages.');
  t('Select an UNBIS classification for this <em>Press Release</em>.');
  t('Select associated topics for this <em>Press Release</em>.');
  t('Select the date and time of publication for this <em>Press Release</em>.');
  t('TEMPORAL, Institutional contact data.');
  t('TEMPORAL, contact details.');
  t('Teaser');
  t('Topic');
  t('UNBIS');

  return $field_instances;
}
