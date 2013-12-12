<?php
/**
 * @file
 * cepal_banner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cepal_banner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cepal_banner_image_default_styles() {
  $styles = array();

  // Exported image style: main_slide.
  $styles['main_slide'] = array(
    'name' => 'main_slide',
    'label' => 'main_slide',
    'effects' => array(
      4 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 800,
          'height' => 500,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 0,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: promotion.
  $styles['promotion'] = array(
    'name' => 'promotion',
    'label' => 'promotion',
    'effects' => array(
      5 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 150,
          'height' => 150,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 0,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: top_page.
  $styles['top_page'] = array(
    'name' => 'top_page',
    'label' => 'Top page',
    'effects' => array(
      6 => array(
        'label' => 'Javascript crop',
        'help' => 'Create a crop with a javascript toolbox.',
        'effect callback' => 'imagecrop_effect',
        'form callback' => 'imagecrop_effect_form',
        'summary theme' => 'imagecrop_effect_summary',
        'module' => 'imagecrop',
        'name' => 'imagecrop_javascript',
        'data' => array(
          'width' => 600,
          'height' => 250,
          'xoffset' => '',
          'yoffset' => '',
          'resizable' => 0,
          'downscaling' => 0,
          'aspect_ratio' => 'CROP',
          'disable_if_no_data' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cepal_banner_node_info() {
  $items = array(
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('@TODO : traducir
Pieza gráfica para promoción de contenidos internos y externos.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
