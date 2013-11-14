<?php
/**
 * @file
 * cepal_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_projects_node_info() {
  $items = array(
    'cepal_project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Use this content to create de definition of a <em>Project</em>.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
