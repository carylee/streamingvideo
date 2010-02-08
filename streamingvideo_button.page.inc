<?php
// $Id$

/**
  * @file
  * Page functions for module Streaming Video Button
  */
  
/**
  * Display input page
  */

function streamingvideo_button_page_input() {
  module_invoke('admin_menu', 'supress');
  
  // Add JavaScript
  drupal_add_js(drupal_get_path('module', 'streamingvideo_button') . '/js/dialog.js');
  
  // Create page
  $content = '<b>This is a test</b>';
  
  echo theme('streamingvideo_button_page', $content);
  
}
  