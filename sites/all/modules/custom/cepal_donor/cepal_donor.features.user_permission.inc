<?php
/**
 * @file
 * cepal_donor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_donor_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_donor content'.
  $permissions['create cepal_donor content'] = array(
    'name' => 'create cepal_donor content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_donor content'.
  $permissions['delete any cepal_donor content'] = array(
    'name' => 'delete any cepal_donor content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_donor content'.
  $permissions['delete own cepal_donor content'] = array(
    'name' => 'delete own cepal_donor content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_donor content'.
  $permissions['edit any cepal_donor content'] = array(
    'name' => 'edit any cepal_donor content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_donor content'.
  $permissions['edit own cepal_donor content'] = array(
    'name' => 'edit own cepal_donor content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
