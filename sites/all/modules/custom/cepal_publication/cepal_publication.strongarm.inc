<?php
/**
 * @file
 * cepal_publication.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cepal_publication_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cepal_publication';
  $strongarm->value = 0;
  $export['comment_anonymous_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cepal_publication';
  $strongarm->value = '1';
  $export['comment_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cepal_publication';
  $strongarm->value = 1;
  $export['comment_default_mode_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cepal_publication';
  $strongarm->value = '50';
  $export['comment_default_per_page_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cepal_publication';
  $strongarm->value = 1;
  $export['comment_form_location_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cepal_publication';
  $strongarm->value = '1';
  $export['comment_preview_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cepal_publication';
  $strongarm->value = 1;
  $export['comment_subject_field_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cepal_publication';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '32',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cepal_publication';
  $strongarm->value = '4';
  $export['language_content_type_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cepal_publication';
  $strongarm->value = array();
  $export['menu_options_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cepal_publication';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cepal_publication';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cepal_publication';
  $strongarm->value = '1';
  $export['node_preview_cepal_publication'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cepal_publication';
  $strongarm->value = 0;
  $export['node_submitted_cepal_publication'] = $strongarm;

  return $export;
}
