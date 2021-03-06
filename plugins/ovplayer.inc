<?php
// $Id$

/**
 * @file
 * Wysiwyg API integration for streaming video module.
 */

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function streamingvideo_button_ovplayer_plugin() {
  $plugins['ovplayer'] = array(
    'title' => t('Open video player'),
    'vendor url' => 'http://github.com/carylee/streamingvideo',
    'icon file' => 'ovplayer.gif',
    'icon title' => t('Insert a streaming video'),
    'settings' => array(
      'dialog' => array(
        'url' => base_path() . 'index.php?q=admin/streamingvideo-button/dialog',
        'width' => 400,
        'height' => 300,
        ),
      ),
  );
  return $plugins;
}

