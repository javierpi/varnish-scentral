<?php
/**
 * @file
 * cepal_speech.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_speech_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_speech_node_info() {
  $items = array(
    'cepal_speech' => array(
      'name' => t('Speech'),
      'base' => 'node_content',
      'description' => t('Use this content type to publish a <em>speech</em> from some person with its associated information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
