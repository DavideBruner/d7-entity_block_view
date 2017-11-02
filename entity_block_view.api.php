<?php

/**
 * Implements hook_delta_bean_render().
 *
 * @param $delta
 * @param $entity_id
 * @param null $entity_id_position
 * @param array $args
 */
function hook_delta_bean_render($delta, $entity_id, $entity_id_position = NULL, $args = []) {}

/**
 * Implements hook_bid_bean_render().
 *
 * @param $bid
 * @param $entity_id
 * @param null $entity_id_position
 * @param array $args
 */
function hook_bid_bean_render($bid, $entity_id, $entity_id_position = NULL, $args = []) {}

/**
 * Implements hook_entity_block_view_pre_render().
 *
 * @param &$block
 * @param $delta
 * @param &$bean
 * @param $args
 */
function hook_entity_block_view_pre_render(&$block, $delta, &$bean, $args = []) {}