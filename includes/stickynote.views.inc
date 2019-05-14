<?php
/**
 * @file
 * The stickynote.views.inc file for the stickynote module
 */

/**
 * Implements hook_views_data().
 */
function stickynote_views_data() {
  $data['stickynote']['table']['group'] = t('Sticky Notes table');

  $data['stickynote']['table']['base'] = array(
    'field' => 'snid',
    'title' => t('Sticky Notes'),
    'help' => t("Sticky Notes table contains sticky note content for given paths."),
    'weight' => -10,
  );

  $data['stickynote']['snid'] = array(
    'title' => t('Sticky Note ID'),
    'help' => t('Sticky Note ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['stickynote']['note'] = array(
    'title' => t('Note'),
    'help' => t('Sticky Note contents'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['stickynote']['uid'] = array(
    'title' => t('Sticky Note Author'),
    'help' => t('Sticky Note author'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['stickynote']['url'] = array(
    'title' => t('URL'),
    'help' => t('URL sticky note is saved on.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  $data['stickynote']['created'] = array(
    'title' => t('Created time'),
    'help' => t('Created timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['stickynote']['updated'] = array(
    'title' => t('Updated timed'),
    'help' => t('Updated timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
