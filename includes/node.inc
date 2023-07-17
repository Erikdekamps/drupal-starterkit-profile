<?php

/**
 * @file
 * Installation functionality for creating nodes.
 */

use Drupal\node\Entity\Node;
use Drupal\path_alias\Entity\PathAlias;

/**
 * Create the base nodes.
 */
function _drupal_starterkit_profile_create_base_nodes() {

  // Generate the homepage node.
  $node = Node::create([
    'type' => 'page',
    'title' => 'Home',
    'body' => [
      'value' => 'De voorpagina.',
      'format' => 'basic_html',
    ],
  ]);
  $node->save();

  // Generate the URL alias for the homepage.
  PathAlias::create([
    'path' => '/node/' . $node->id(),
    'alias' => '/home',
    'langcode' => 'nl',
  ])->save();
}
