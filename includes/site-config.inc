<?php

/**
 * @file
 * Installation functionality for site configuration.
 */

/**
 * Create the base nodes.
 */
function _drupal_starterkit_profile_change_site_config() {

  $config_factory = \Drupal::configFactory();

  // Set the homepage as homepage.
  $site_config = $config_factory->getEditable('system.site');
  $site_config->set('page.front', '/home')->save();

  // Set pursubsite theme as default theme and adminimal theme as admin theme.
  $theme_config = $config_factory->getEditable('system.theme');
  $theme_config->set('default', 'olivero');
  $theme_config->set('admin', 'gin');
  $theme_config->save();

  // Enable "Use the administration theme when editing or creating content".
  $node_config = $config_factory->getEditable('node.settings');
  $node_config->set('use_admin_theme', '1');
  $node_config->save();
}
