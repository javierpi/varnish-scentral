<?php
/**
 * @file
 * cepal_organization.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_organization_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_organization_node_info() {
  $items = array(
    'cepal_organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => t('Use this content type to store the information about an <em>Organization</em>.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
