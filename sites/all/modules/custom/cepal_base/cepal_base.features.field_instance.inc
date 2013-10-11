<?php
/**
 * @file
 * cepal_base.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cepal_base_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-unbis-field_unbis_level'
  $field_instances['taxonomy_term-unbis-field_unbis_level'] = array(
    'bundle' => 'unbis',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Nivel del termino',
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_unbis_level',
    'label' => 'Nivel',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-unbis-field_unbis_number'
  $field_instances['taxonomy_term-unbis-field_unbis_number'] = array(
    'bundle' => 'unbis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Código UNBIS del término de taxonomía.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_unbis_number',
    'label' => 'Número',
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
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Código UNBIS del término de taxonomía.');
  t('Nivel');
  t('Nivel del termino');
  t('Número');

  return $field_instances;
}
