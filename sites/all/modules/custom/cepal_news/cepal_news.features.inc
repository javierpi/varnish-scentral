<?php
/**
 * @file
 * cepal_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_news_node_info() {
  $items = array(
    'cepal_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Use <em>news</em> to publish some note in a division or sitewide.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
