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
Cada una de las partes, charlas, mesas redondas, discursos o cualquier otra actividad de una conferencia caracterizada por tener una hora de inicio y fin en el mismo día, con uno o varios ponentes o participantes y en una misma sala. Siempre va asociada a una conferencia.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
