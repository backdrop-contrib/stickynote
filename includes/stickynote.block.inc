<?php

/**
 * @file
 * Defines the stickynote block contents
 */

function stickynote_block_contents() {
  $output = '';

  $stickynote = (object)array (
    'snid' => '',
    'type' => 'stickynote',
    'note' => '',
    'url' => '',
    'uid' => '',
  );
  
  $form = drupal_get_form('stickynote_add_form', $stickynote);
  $output .= '<div id="add-edit-form">' . drupal_render($form) . '</div>';
  return $output;
}
