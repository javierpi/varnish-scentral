<?php
/**
 * @file
 * cepal_gi.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_gi_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_gi_node_info() {
  $items = array(
    'cepal_graphic_info' => array(
      'name' => t('Graphic Information'),
      'base' => 'node_content',
      'description' => t('Use this content type to create the content for a <em>Infography</em> or <em>Information Sheet</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
