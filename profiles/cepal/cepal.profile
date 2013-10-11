<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function cepal_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  //$form['site_information']['site_mail']['#default_value'] = '';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  //$form['admin_account']['account']['mail']['#default_value'] = '';
  $form['server_settings']['site_default_country']['#default_value'] = 'CL'; //Country  Alpha-2 ISO code.
}


/**
 * Implements hook_install_tasks()
 *
 * Adds extra tasks during the instalation process.
 */
function cepal_install_tasks() {
  return array(
    'cepal_set_variables' => array(
      'display_name'  =>  st('Set Website Variables'),
      'display' => TRUE,
    ),
  );
}


/**
* Implements hook_install_tasks() callback
*/
function cepal_set_variables() {
  variable_set('pathauto_reduce_ascii', TRUE);
  variable_set('pathauto_transliterate', TRUE);
  // variable_set('pathauto_ignore_words', PATHAUTO_IGNORE_WORDS); //define custom words to ignore in pathauto alias
  variable_set('pathauto_node_pattern', '[node:title]');  
  cache_clear_all();
}


