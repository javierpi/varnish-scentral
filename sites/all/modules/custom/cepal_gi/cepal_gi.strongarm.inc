<?php
/**
 * @file
 * cepal_gi.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cepal_gi_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cepal_graphic_info';
  $strongarm->value = 0;
  $export['comment_anonymous_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cepal_graphic_info';
  $strongarm->value = '1';
  $export['comment_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cepal_graphic_info';
  $strongarm->value = 0;
  $export['comment_default_mode_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cepal_graphic_info';
  $strongarm->value = '50';
  $export['comment_default_per_page_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cepal_graphic_info';
  $strongarm->value = 1;
  $export['comment_form_location_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cepal_graphic_info';
  $strongarm->value = '1';
  $export['comment_preview_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cepal_graphic_info';
  $strongarm->value = 1;
  $export['comment_subject_field_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_cepal_graphic_info';
  $strongarm->value = 0;
  $export['entity_translation_hide_translation_links_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_cepal_graphic_info';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__cepal_graphic_info';
  $strongarm->value = array(
    'default_language' => 'xx-et-current',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cepal_graphic_info';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '10',
        ),
        'language' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cepal_graphic_info';
  $strongarm->value = '4';
  $export['language_content_type_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cepal_graphic_info';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cepal_graphic_info';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cepal_graphic_info';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cepal_graphic_info';
  $strongarm->value = '1';
  $export['node_preview_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cepal_graphic_info';
  $strongarm->value = 0;
  $export['node_submitted_cepal_graphic_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cepal_graphic_info_en_pattern';
  $strongarm->value = 'informationsheet/[node:created:custom:Y]/[node:created:custom:d]/[node:created:custom:m]/[node:title_field]';
  $export['pathauto_node_cepal_graphic_info_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cepal_graphic_info_es_pattern';
  $strongarm->value = 'hojainformativa/[node:created:custom:Y]/[node:created:custom:d]/[node:created:custom:m]/[node:title_field]';
  $export['pathauto_node_cepal_graphic_info_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cepal_graphic_info_pattern';
  $strongarm->value = 'hojainformativa/[node:created:custom:Y]/[node:created:custom:d]/[node:created:custom:m]/[node:title_field]';
  $export['pathauto_node_cepal_graphic_info_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cepal_graphic_info_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_cepal_graphic_info_und_pattern'] = $strongarm;

  return $export;
}
