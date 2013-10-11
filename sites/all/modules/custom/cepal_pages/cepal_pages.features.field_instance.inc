<?php
/**
 * @file
 * cepal_pages.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cepal_pages_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cepal_page-field_page_body'
  $field_instances['node-cepal_page-field_page_body'] = array(
    'bundle' => 'cepal_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insert here the content for this page.',
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
    'field_name' => 'field_page_body',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-cepal_page-field_page_files'
  $field_instances['node-cepal_page-field_page_files'] = array(
    'bundle' => 'cepal_page',
    'deleted' => 0,
    'description' => 'Is possible to add some attached files for this page as a complementary information.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
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
    'field_name' => 'field_page_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'pages',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-cepal_page-field_page_link'
  $field_instances['node-cepal_page-field_page_link'] = array(
    'bundle' => 'cepal_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is possible to add link references for this page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
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
    'field_name' => 'field_page_link',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-cepal_page-field_page_referece'
  $field_instances['node-cepal_page-field_page_referece'] = array(
    'bundle' => 'cepal_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Is possible to add references to another pages on this site.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
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
    'field_name' => 'field_page_referece',
    'label' => 'Refereces',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'STARTS_WITH',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 35,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Files');
  t('Insert here the content for this page.');
  t('Is possible to add link references for this page.');
  t('Is possible to add references to another pages on this site.');
  t('Is possible to add some attached files for this page as a complementary information.');
  t('Links');
  t('Refereces');

  return $field_instances;
}
