<?php
/**
 * @file
 * cepal_feed_item.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cepal_feed_item_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cepal_feed_item content'.
  $permissions['create cepal_feed_item content'] = array(
    'name' => 'create cepal_feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any cepal_feed_item content'.
  $permissions['delete any cepal_feed_item content'] = array(
    'name' => 'delete any cepal_feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own cepal_feed_item content'.
  $permissions['delete own cepal_feed_item content'] = array(
    'name' => 'delete own cepal_feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any cepal_feed_item content'.
  $permissions['edit any cepal_feed_item content'] = array(
    'name' => 'edit any cepal_feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own cepal_feed_item content'.
  $permissions['edit own cepal_feed_item content'] = array(
    'name' => 'edit own cepal_feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
