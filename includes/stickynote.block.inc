<?php
/**
 * @file
 * Defines the stickynote block contents
 */

/**
 * Return the stickynote block's add form
 * @return string
 */
function stickynote_block_contents() {
  $form = backdrop_get_form('stickynote_add_form', '');
  return '<div id="add-edit-form">' . backdrop_render($form) . '</div>';
}
