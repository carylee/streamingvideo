<?php
// $Id: ovplayer.inc,v 1.1 2009/08/24 20:48:05 joachim Exp $

/**
 * @file
 * Wysiwyg API integration for columns filter module.
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
        'width' => 700,
        'height' => 500,
        ),
      ),
  );
  return $plugins;
}

