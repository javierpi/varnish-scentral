<?php
/**
 * @file
 * cepal_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_articles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cepal_articles_node_info() {
  $items = array(
    'cepal_article' => array(
      'name' => t('Artículo'),
      'base' => 'node_content',
      'description' => t('Use this content type to create an <em>Opinion Columns</em> or <em>Messages</em> from authorities.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
