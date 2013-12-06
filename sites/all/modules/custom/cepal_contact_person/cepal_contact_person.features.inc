<?php
/**
 * @file
 * cepal_contact_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_contact_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_contact_person_node_info() {
  $items = array(
    'cepal_contact' => array(
      'name' => t('Contact Person'),
      'base' => 'node_content',
      'description' => t('The information from a <em>Contact Person</em>, to send or ask her/him for more information.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  return $items;
}
