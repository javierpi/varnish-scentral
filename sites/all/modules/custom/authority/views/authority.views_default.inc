<?php
/**
 * @file
 * authorities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function authority_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publication_authorities';
  $view->description = 'A list of publication authorities';
  $view->tag = 'default';
  $view->base_table = 'eck_authority';
  $view->human_name = 'Publication Authorities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publication Authors ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Campo: Authority: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Campo: Authority: Last Name */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['label'] = 'Lastname(s)';
  /* Campo: Authority: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name(s)';
  /* Campo: Authority: Enlace de edición */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Editar';
  /* Sort criterion: Authority: Last Name */
  $handler->display->display_options['sorts']['lastname']['id'] = 'lastname';
  $handler->display->display_options['sorts']['lastname']['table'] = 'eck_authority';
  $handler->display->display_options['sorts']['lastname']['field'] = 'lastname';
  /* Sort criterion: Authority: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'eck_authority';
  $handler->display->display_options['sorts']['name']['field'] = 'name';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/authorities';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Autorities';
  $handler->display->display_options['menu']['description'] = 'The list of publication authors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'lastname' => 'lastname',
    'name' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = ',';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Authority: Last Name */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['label'] = '';
  $handler->display->display_options['fields']['lastname']['element_label_colon'] = FALSE;
  /* Campo: Authority: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'eck_authority';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Authority: Last Name */
  $handler->display->display_options['sorts']['lastname']['id'] = 'lastname';
  $handler->display->display_options['sorts']['lastname']['table'] = 'eck_authority';
  $handler->display->display_options['sorts']['lastname']['field'] = 'lastname';
  /* Sort criterion: Authority: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'eck_authority';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $translatables['publication_authories'] = array(
    t('Master'),
    t('Publication Authors '),
    t('more'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Id'),
    t('.'),
    t(','),
    t('Lastname(s)'),
    t('Name(s)'),
    t('Editar'),
    t('Page'),
    t('Entity Reference'),
  );
  $export['publication_authorities'] = $view;

  return $export;
}
