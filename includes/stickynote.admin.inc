<?php
/**
 * @file
 * Defines the admin page for the stickynote module
 */

/**
 * Admin page callback function.
 *
 * @return string
 */
function stickynote_info() {
  $notes_per_page = 20;
  $sort = config_get('stickynote.settings', 'stickynote_sort');
  $header = array(
    array(
      'data' => 'ID',
      'field' => 's.snid',
    ),
    array(
      'data' => 'Note',
      'field' => 's.note',
    ),
    array(
      'data' => 'URL',
      'field' => 's.url',
    ),
    array(
      'data' => 'User',
      'field' => 's.uid',
    ),
    array(
      'data' => 'Created',
      'field' => 's.created',
      'sort' => $sort,
    ),
  );
  $query = db_select('stickynote', 's')->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('s')
    ->orderByHeader($header)
    ->limit($notes_per_page);

  $result = $query->execute();

  $notes = array();
  foreach ($result as $key => $row) {
    $user = user_load($row->uid, FALSE);
    if (!empty($user)) {
      $user_name = l($user->name, 'user/' . $user->uid);
    }
    else {
      $user_name = '';
    }
    if (!backdrop_valid_path($row->url)) {
      db_delete('stickynote')
        ->condition('snid', $row->snid)
        ->execute();
    }
    else {
      $notes[] = array(
        'data' => array(
          'snid' => l($row->snid, 'stickynote/' . $row->snid),
          'note' => filter_xss($row->note),
          'url' => l($row->url, $row->url),
          'user' => $user_name,
          'created' => date('n/j/Y - G:i', $row->created),
        ),
      );
    }
  }

  $build['stickynotes_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $notes,
    '#prefix' => t('This table lists all existing sticky notes and their respective data.'),
    '#empty' => t('There are currently no sticky notes.'),
  );
  $build['stickynotes_pager'] = array('#theme' => 'pager');

  return $build;
}

/**
 * Stickynote configuration options
 */
function stickynote_config() {
  $config = config('stickynote.settings');
  $form = array();
  $form['#config'] = 'stickynote.settings';

  // Gets the list of defined date formats and attributes.
  $date_types = system_get_date_formats();
  foreach ($date_types as $machine_name => $value) {
    $options[$machine_name] = check_plain(t('@name format', array('@name' => $value['label'])) . ': ' . format_date(REQUEST_TIME, $machine_name));
  }

  $form['stickynote_date_format'] = array(
    '#type' => 'select',
    '#title' => t('Date Format'),
    '#options' => $options,
    '#default_value' => $config->get('stickynote_date_format'),
    '#description' => t('Select a date format for sticky notes.'),
  );

  $form['stickynote_sort'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#options' => array(
      'asc' => 'Ascending',
      'desc' => 'Descending',
    ),
    '#default_value' => $config->get('stickynote_sort'),
    '#description' => t('Select sorting criteria for sticky note entries.'),
  );

  return system_settings_form($form);
}
