<?php
/**
 * @file
 * cepal_pages.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_pages_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_page content'.
  $permissions['create cepal_page content'] = array(
    'name' => 'create cepal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_page content'.
  $permissions['delete any cepal_page content'] = array(
    'name' => 'delete any cepal_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_page content'.
  $permissions['delete own cepal_page content'] = array(
    'name' => 'delete own cepal_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_page content'.
  $permissions['edit any cepal_page content'] = array(
    'name' => 'edit any cepal_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_page content'.
  $permissions['edit own cepal_page content'] = array(
    'name' => 'edit own cepal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
