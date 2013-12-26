<?php
/**
 * @file
 * cepal_publication.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_publication_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_publication content'.
  $permissions['create cepal_publication content'] = array(
    'name' => 'create cepal_publication content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_publication content'.
  $permissions['delete any cepal_publication content'] = array(
    'name' => 'delete any cepal_publication content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_publication content'.
  $permissions['delete own cepal_publication content'] = array(
    'name' => 'delete own cepal_publication content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_publication content'.
  $permissions['edit any cepal_publication content'] = array(
    'name' => 'edit any cepal_publication content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_publication content'.
  $permissions['edit own cepal_publication content'] = array(
    'name' => 'edit own cepal_publication content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
