<?php
/**
 * @file
 * cepal_common.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cepal_common_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_id_sade'
  $field_bases['field_id_sade'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_id_sade',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
