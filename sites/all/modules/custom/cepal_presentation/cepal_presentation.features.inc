<?php
/**
 * @file
 * cepal_presentation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_presentation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_presentation_node_info() {
  $items = array(
    'cepal_presentation' => array(
      'name' => t('Presentation'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a <em>Presentation</em> from authorities ir highlighted speakers.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
