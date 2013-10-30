<?php
/**
 * @file
 * Este archivo contiene una interface
 */

/**
 * Interface para la migracion de archivos, para obligar a las clases a la
 * implementacion de ciertas funciones.
 */
interface BaseMigracionInterface {



   /**
   * Debe devolver un arreglo que explique cada uno de los campos del xml que
   * se quiere migrar.
   * Ejemplo de lo anterior:
   *  return array(
   *   'id_protrack' => t('ID from ProTrack'),
   *   'titulo' => t('Title'),
   * );
   *
   * @return array
   */
  public static function getXMLFields();



  /**
   * Debe deviolver un arreglo que explicite las equivalencias normales.
   *
   * La forma exacta del arreglo que se debe devolver es la siguiente:
   *
   *  return array(
   *   'id_protrack' => array('field' => false, 'callback' => ''),
   *   'titulo' => array('field' => 'title', 'callback' => ''),
   * );
   *
   * field: si es false no se migra. Deberia ser el nombre del campo Drupal
   * callback: funcion de callback para preproceso del dato
   */
  public static function getNormalEquivalences();



  /**
   * Debe devolver un arreglo con los campos Drupal que tiene valores fijos.
   *
   * Ejemplo:
   *  return array(
   *   'translate' => true,
   * );
   *
   * @return array
   */
  public static function getDefaultEquivalences();




}