<?php
/**
 * @file
 * cepal_session.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_session_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_session_node_info() {
  $items = array(
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => t('@TODO : traducir
Cada una de las juntas de una conferencia, caracterizada por tener uno o varios ponentes en una ubicación determinada, con una hora de inicio y de fin.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
