<?php
// $Id:$

/**
 * @file
 * Wysiwyg API integration for streaming video module.
 */

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function streamingvideo_videobutton_plugin() {
  $plugins['columnbreak'] = array(
    'title' => t('Column break'),
    'vendor url' => 'http://github.com/carylee/streamingvideo',
    'icon file' => 'videobutton.gif',
    'icon title' => t('Insert a streaming video player'),
    'settings' => array(),
  );
  return $plugins;
}

