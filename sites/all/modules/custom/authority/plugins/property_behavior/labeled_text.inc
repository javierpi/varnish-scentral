<?php
/*
 * In a property behavior plugin we want to hijack drupal when it is relavant. In this case we
 * want to do it when an entity with a property using our behavior is being manipulated: created, updated, saved,
 * shown, etc.
 * 
 * So the plugin implementation in ECK gives an opportunity to do this in multiple places. Currelty this are the
 * places where we can do it
 * 
 * entity_save: save gets called everytime the entity is being saved.
 * 
 * entity_insert: insert is a subset of save, in which it only gets called on a new entity
 * entity_update: insert is a subset of save, in which it only gets called on an entity that was loaded (edit mode)
 * 
 * We are also allowed to give a default_widget for this behavior, and a default_formatter
 * 
 * As new use cases arise, I am sure that this would be expanded to many other cases.
 * 
 * THE PLUGIN
 * 
 * The plugin is a very simple array with a label, and with the different callbacks that we want to implement.
 * 
 * In this example we are using the default_widget, default_formatter, and the save options. 
 * After the plugin array we give the functions that we want call at these different stages.
 */

$plugin = array(
  'label' => "Labeled Text",
  //'entity_save' => 'eck_title_property_entity_save',
  'entity_view' => 'authority_labeled_text_property_entity_view',
 // 'entity_info' => 'eck_labeled_text_property_entity_info',
  'default_widget' => 'authority_labeled_text_property_widget',
  'default_formatter' => 'authority_labeled_text_property_formatter'
);

/**
 * Define a rendarble array to input a value for the property using this behavior 
 *
 * @param $entity: and entity object that contains the property for which this behavior is relevant
 * @param $property: the name of the property (string) that is using this behavior
 * 
 * @return a rendarable array use when the input form for this entity is displayed
 */
function authority_labeled_text_property_widget($property, $vars){
  $entity = $vars['entity'];
  $labeled_text = _authority_labeled_text_property_extract_title($entity, $property);

  return array(
    '#type' => 'textfield',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => $labeled_text,
    '#required' => TRUE
  );
}

function authority_labeled_text_property_formatter($property, $vars){
  $entity = $vars['entity'];
  $labeled_text_value = _authority_labeled_text_property_extract_title($entity, $property);
  
  $entity_type = EntityType::loadByName($entity->entityType());
  $label = '<strong>' . $entity_type->properties[$property]['label'] . '</strong>';
  
  $label_and_text = $label.': '.$labeled_text_value;
  return array('#markup' => "<p>{$label_and_text}</p>");
}

function authority_title_property_entity_view($property, $vars){
   $entity = $vars['entity'];
   $title = _authority_labeled_text_extract_fullname($entity, $property);
   if(empty($title)){
     $title = "{$entity->entityType()} : {$entity->id}";
   }
   
   drupal_set_title($title);
}


function _authority_labeled_text_property_extract_title($entity, $property){
  $labeled_text = "";
  if(isset($entity->{$property})){
    $labeled_text = $entity->{$property};
  }
  
  return $labeled_text;
}

function _authority_labeled_text_property_extract_fullname($entity, $property){
  $labeled_text = "";
  dsm($entity);
  if(isset($entity->{$property})){
    $labeled_text = $entity->{$property};
  }
  
  return $labeled_text;
}

function _authority_labeled_text_property_extract_label($vars, $entity, $property){
  $labeled_text_label = "";
  if(isset($entity->{$property})){
  
    $labeled_text_label = $property;
  }
  
  return $labeled_text_label;
}
