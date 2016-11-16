<?php
/**
 * @file
 * cepal_gi.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_gi_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_graphic_info content'.
  $permissions['create cepal_graphic_info content'] = array(
    'name' => 'create cepal_graphic_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_graphic_info content'.
  $permissions['delete any cepal_graphic_info content'] = array(
    'name' => 'delete any cepal_graphic_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_graphic_info content'.
  $permissions['delete own cepal_graphic_info content'] = array(
    'name' => 'delete own cepal_graphic_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_graphic_info content'.
  $permissions['edit any cepal_graphic_info content'] = array(
    'name' => 'edit any cepal_graphic_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_graphic_info content'.
  $permissions['edit own cepal_graphic_info content'] = array(
    'name' => 'edit own cepal_graphic_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
