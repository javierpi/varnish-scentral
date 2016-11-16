<?php
/**
 * @file
 * cepal_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_publication_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cepal_publication_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cepal_publication_node_info() {
  $items = array(
    'cepal_publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a generic <em>Publication</em>.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
