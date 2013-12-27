<?php
/**
 * @file
 * cepal_feed_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_feed_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_feed_item_node_info() {
  $items = array(
    'cepal_feed_item' => array(
      'name' => t('Cepal News Feed item'),
      'base' => 'node_content',
      'description' => t('This content type is being used for automatically aggregated content from feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
