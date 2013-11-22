<?php
/**
 * @file
 * cepal_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_pages_node_info() {
  $items = array(
    'cepal_page' => array(
      'name' => t('Basic Page HTML'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an "About us" page.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
