<?php

/**
 * @param $delta
 * @param $entity_id
 * @param $entity_id_position
 */
function entity_block_view_render($delta, $entity_id, $entity_id_position = NULL, $args = []) {

  if(is_numeric($delta)) {
    $bean = bean_load($delta);
  } else {
    $bean = bean_load_delta($delta);
  }

  if($bean) {

    if(!empty($entity_id)) {
      $bean->entity_id = $entity_id;
    } else if(!empty($entity_id_position)) {
      $bean->entity_id_position = $entity_id_position;
    }

    $bean_block = block_load('bean', $delta);

    $block = _block_get_renderable_array(_block_render_blocks(array($bean_block)));

    // Define a pre render function
    foreach (module_implements('entity_block_view_pre_render') as $module) {
      $function = $module . '_entity_block_view_pre_render';
      $block_delta = "bean_$delta";
      // will call all modules implementing hook_hook_name
      // and can pass each argument as reference determined
      // by the function declaration
      $function($block, $block_delta, $bean, $args);
    }

    return drupal_render($block);

  } else {
    drupal_set_message(t("The Block @delta doesn't exist.", array('@delta' => $delta)), 'warning');
    return '';
  }

}