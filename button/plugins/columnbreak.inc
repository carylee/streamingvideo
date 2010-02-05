<?php
// $Id: columnbreak.inc,v 1.1 2009/08/24 20:48:05 joachim Exp $

/**
 * @file
 * Wysiwyg API integration for columns filter module.
 */

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function columns_filter_columnbreak_plugin() {
  $plugins['columnbreak'] = array(
    'title' => t('Column break'),
    'vendor url' => 'http://drupal.org/project/columns_filter',
    'icon file' => 'columnbreak.gif',
    'icon title' => t('Insert a column break'),
    'settings' => array(),
  );
  return $plugins;
}

