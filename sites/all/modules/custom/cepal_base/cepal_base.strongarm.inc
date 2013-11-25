<?php
/**
 * @file
 * cepal_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cepal_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_entity_types';
  $strongarm->value = array(
    'node' => 'node',
    'file' => 'file',
    'taxonomy_term' => 0,
    'comment' => 0,
    'user' => 0,
  );
  $export['entity_translation_entity_types'] = $strongarm;

  return $export;
}
