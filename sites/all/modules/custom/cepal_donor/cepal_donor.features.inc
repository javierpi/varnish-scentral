<?php
/**
 * @file
 * cepal_donor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_donor_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_donor_node_info() {
  $items = array(
    'cepal_donor' => array(
      'name' => t('Donor'),
      'base' => 'node_content',
      'description' => t('An entity that donates resources to a project.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
