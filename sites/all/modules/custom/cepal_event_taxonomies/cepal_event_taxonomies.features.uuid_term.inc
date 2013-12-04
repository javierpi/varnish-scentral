<?php
/**
 * @file
 * cepal_event_taxonomies.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cepal_event_taxonomies_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Foro',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '1a4c4933-f71e-4a40-a771-e44d951b84e0',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  $terms[] = array(
    'name' => 'Comité Plenario',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '1ecd2938-e8d7-4144-8267-95b082451d32',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => '6bbe9c09-c2b3-41c4-9759-795e440c0c28',
    ),
  );
  $terms[] = array(
    'name' => 'Cátedra Magistral',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '20b577f3-4188-4489-b4dc-da408abeac75',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'e576a006-2a12-42c1-88cc-7b3f85931444',
    ),
  );
  $terms[] = array(
    'name' => 'Organizaciones Intergubernamentales',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '316191ad-6257-47f5-980e-71927e4bb38b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Gobiernos - Cuerpo Diplomático',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '34256ce0-7566-43c7-a2fa-3ee4134a5d84',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Media',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '34580e6b-47c2-4b36-bcdd-00966c4a7a0a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Gobiernos - Ministros',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3b5ccf36-42f9-4b5b-9d02-6283a4f7f587',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Jornada',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '3c765408-4e89-4911-8d2f-ec1f67f9a4f0',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  $terms[] = array(
    'name' => 'Otros',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '3f3a5817-4267-4f72-9678-dc84f085e85e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
  );
  $terms[] = array(
    'name' => 'Seminario',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '442c826b-f7a0-4f45-b958-a7f57cfd3806',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  $terms[] = array(
    'name' => 'ONGs',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53be5bb8-f69d-498e-bfdd-c32aeffca36b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Prensa',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6510d4b5-e7ec-47b5-a975-1144f58319df',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Conferencia',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '6bbe9c09-c2b3-41c4-9759-795e440c0c28',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
  );
  $terms[] = array(
    'name' => 'Visita Oficial',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6ed61cd8-a756-4257-b6d4-e5f0739ad514',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'e576a006-2a12-42c1-88cc-7b3f85931444',
    ),
  );
  $terms[] = array(
    'name' => 'Otras grandes conferencias',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '84434851-2652-4159-a184-422de7f2d1fc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => '6bbe9c09-c2b3-41c4-9759-795e440c0c28',
    ),
  );
  $terms[] = array(
    'name' => 'Lanzamiento',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '97a5f3c5-5b85-4e05-938d-0a15002de150',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'e576a006-2a12-42c1-88cc-7b3f85931444',
    ),
  );
  $terms[] = array(
    'name' => 'Mesa Redonda',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '98514d31-8b59-4222-a8f3-ba7e85998a66',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  $terms[] = array(
    'name' => 'Agencias de NNUU y Organizaciones Internacionales',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9b4bbbb6-f7fa-4587-97ee-63cea0b4856d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Otros',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a8a9cbfd-88e8-48e8-bd58-cdba59dee80c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Consulta',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aa4fb0a6-9890-43ad-9ab4-5311ebd9f4dc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  $terms[] = array(
    'name' => 'Conferencia Prensa',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'b76e338d-8ec8-4d52-b6f7-17cf4c05643c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'e576a006-2a12-42c1-88cc-7b3f85931444',
    ),
  );
  $terms[] = array(
    'name' => 'Técnico',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
  );
  $terms[] = array(
    'name' => 'Gobiernos',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cc06af0b-2b3f-4ec5-a535-adda95a78179',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Gobiernos - Delegados',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2ce0619-7d0c-4013-b208-5b00cd7642ef',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Expertos',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd7ef4bda-a058-404f-b36b-3797eac966db',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'audience_type',
  );
  $terms[] = array(
    'name' => 'Varios',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'e576a006-2a12-42c1-88cc-7b3f85931444',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
  );
  $terms[] = array(
    'name' => 'Órgano subsidiario',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e9b138a4-6094-4a3f-9f89-9d018151ef6f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => '6bbe9c09-c2b3-41c4-9759-795e440c0c28',
    ),
  );
  $terms[] = array(
    'name' => 'Periodo de sesiones',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'f8720e1b-6151-4ad5-9589-737871892a5b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => '6bbe9c09-c2b3-41c4-9759-795e440c0c28',
    ),
  );
  $terms[] = array(
    'name' => 'Reunión',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'fb56627b-22b3-4a0d-9804-be2740801d54',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'parent' => array(
      0 => 'bdeb17c5-3412-4bde-85a7-e5370b3fc606',
    ),
  );
  return $terms;
}
