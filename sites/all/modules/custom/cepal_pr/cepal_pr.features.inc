<?php
/**
 * @file
 * cepal_pr.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_pr_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_pr_node_info() {
  $items = array(
    'cepal_pr' => array(
      'name' => t('Press Release'),
      'base' => 'node_content',
      'description' => t('Select this content type to create a new <em>Press Release</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
