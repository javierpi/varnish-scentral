<?php
/**
 * @file
 * cepal_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_person_node_info() {
  $items = array(
    'cepal_person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('The personal information from a <em>Person</em>. Includes biography and image.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  return $items;
}
