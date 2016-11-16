<?php
/**
 * @file
 * cepal_organization.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_organization_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_organization content'.
  $permissions['create cepal_organization content'] = array(
    'name' => 'create cepal_organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_organization content'.
  $permissions['delete any cepal_organization content'] = array(
    'name' => 'delete any cepal_organization content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_organization content'.
  $permissions['delete own cepal_organization content'] = array(
    'name' => 'delete own cepal_organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_organization content'.
  $permissions['edit any cepal_organization content'] = array(
    'name' => 'edit any cepal_organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_organization content'.
  $permissions['edit own cepal_organization content'] = array(
    'name' => 'edit own cepal_organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
