<?php
/**
 * @file
 * cepal_organization.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cepal_organization_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cepal_organization-field_country'
  $field_instances['node-cepal_organization-field_country'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the country where this <em>organization</em> is based.',
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
    'field_name' => 'field_country',
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
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_acronym'
  $field_instances['node-cepal_organization-field_organization_acronym'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Acronym for this organization.',
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
    'field_name' => 'field_organization_acronym',
    'label' => 'Acronym',
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
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_adress'
  $field_instances['node-cepal_organization-field_organization_adress'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Street address for this organzation.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_organization_adress',
    'label' => 'Address',
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
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_email'
  $field_instances['node-cepal_organization-field_organization_email'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A contact e-mail for this <em>organization</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
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
    'field_name' => 'field_organization_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_image'
  $field_instances['node-cepal_organization-field_organization_image'] = array(
    'bundle' => 'cepal_organization',
    'deleted' => 0,
    'description' => 'A representative image for this <em>organization</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_organization_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'organization/images',
      'file_extensions' => 'png jpg jpeg',
      'max_filesize' => '512 KB',
      'max_resolution' => '800x600',
      'min_resolution' => '100x100',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_telephone'
  $field_instances['node-cepal_organization-field_organization_telephone'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Contact telephone for this organization.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_organization_telephone',
    'label' => 'Telephone',
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
        'size' => 20,
      ),
      'type' => 'text_textfield',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_type'
  $field_instances['node-cepal_organization-field_organization_type'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the type of this organization.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_organization_type',
    'label' => 'Type',
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
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-cepal_organization-field_organization_url'
  $field_instances['node-cepal_organization-field_organization_url'] = array(
    'bundle' => 'cepal_organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A link (URL) of the website for this organization.',
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
    'field_name' => 'field_organization_url',
    'label' => 'Link',
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
      'title' => 'required',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('A contact e-mail for this <em>organization</em>.');
  t('A link (URL) of the website for this organization.');
  t('A representative image for this <em>organization</em>.');
  t('Acronym');
  t('Acronym for this organization.');
  t('Address');
  t('Contact telephone for this organization.');
  t('Country');
  t('Email');
  t('Image');
  t('Link');
  t('Select the country where this <em>organization</em> is based.');
  t('Select the type of this organization.');
  t('Street address for this organzation.');
  t('Telephone');
  t('Type');

  return $field_instances;
}
