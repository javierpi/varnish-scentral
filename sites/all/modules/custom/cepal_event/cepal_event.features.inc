<?php
/**
 * @file
 * cepal_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_event_node_info() {
  $items = array(
    'cepal_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a specific <em>Event</em>, with a start and end date/time.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
