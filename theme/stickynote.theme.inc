<?php

/**
 * Get notes for referring_url/current url and
 * return as list including edit/delete etc...
 *
 * @param $variables -> contains:
 *             $variables['referring_url'] = url for notes
 *             $variables['notes'] = an array of all notes for referring url
 *             $variables['can_edit'] = a flag with permission to edit
 *             $variables['can_delete'] = a flag with permission to delete * 
 * @TODO: Customize include better themeing for listing.
 */
function theme_stickynote_list($variables) {
  $output = '';

  $header = array();
  $header[] = t('Note');
  if ($variables['can_edit']) {
    $header[] = t('Edit');
  }
  if ($variables['can_delete']) {
    $header[] = t('Delete');
  }
  $header[] = t('Date');

  if (isset($variables['notes'])) {
    $table['header'] = $header;
    $table['rows'] = $variables['notes'];

    $output = theme('table', $table);
  }

  return $output;
}