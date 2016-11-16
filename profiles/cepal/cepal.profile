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
    // Configure features.
    'cepal_configure_site_features' => array(
      'display_name'  =>  st('Configure site features'),
    ),
    'cepal_set_variables' => array(
      'display_name'  =>  st('Set Website Variables'),
      'display' => TRUE,
    ),
    // Set up the basic configuration.
    'cepal_updateconfig' => array(
    ),
  );
}

/**
* Implements hook_install_tasks() callback
*/
function cepal_configure_site_features() {
  // Revert features
  $features = features_get_features();
  foreach ($features as $name => $feature) {
    if ($feature->status) {
      features_revert(array($name => array('variable','user_permission')));
    }
  }
  
  // Create a default role for site administrators, with all available permissions assigned.
  $roles = user_roles(TRUE);  
  if ($adminrole_id = array_search('administrator',$roles)) {
    user_role_grant_permissions($adminrole_id, array_keys(module_invoke_all('permission')));
    // Set this as the administrator role.
    variable_set('user_admin_role', $adminrole_id);

    // Assign to user 1 the "administrator" role.
    db_insert('users_roles')
      ->fields(array('uid' => 1, 'rid' => $adminrole_id))
      ->execute();

  }
  
  cache_clear_all();

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

/*
* Implements hook_install_tasks() callback
* Update configurations in database
*/
function cepalconference_updateconfig() {
  $prefix_updated = db_update('languages')
  ->fields(array(
    'prefix' => 'en',
  ))
  ->condition('language', 'en', '=')
  ->execute();

}


