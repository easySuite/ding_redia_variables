<?php
/**
 * @file
 * Configuration page definition.
 */

/**
 * Generate configuration form.
 */
function ding_redia_variables_admin_form($form, &$form_state) {
  $form = array(
    '#tree' => TRUE,
  );

  $form['ding_redia_variables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Variable configs'),
    '#prefix' => '<div id="ding-redia-variables">',
    '#suffix' => '</div>',
  );

  if (empty($form_state['ding_redia_variables'])) {
    $form_state['ding_redia_variables'] = variable_get('ding_redia_variables', array());
  }
  $form['ding_redia_variables']['table'] = array(
    '#theme' => 'table',
    '#header' => array(t('Variable'), t('Value')),
    '#rows' => $form_state['ding_redia_variables'],
  );

  $form['ding_redia_variables']['variable'] = array(
    '#type' => 'textfield',
    '#title' => t('Variable'),
    '#autocomplete_path' => 'redia/autocomplete/variables',
    '#default_value' => '',
  );

  $form['ding_redia_variables']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add variable'),
    '#submit' => array('ding_redia_variables_add'),
    '#ajax' => array(
      'callback' => 'ding_redia_variables_ajax_callback',
      'wrapper' => 'ding-redia-variables',
    ),
  );

  $form['ding_redia_carousels'] = array(
    '#type' => 'fieldset',
    '#title' => t('Carousels configs'),
    '#prefix' => '<div id="ding-redia-carousels">',
    '#suffix' => '</div>',
  );




  $rows = array('data' => array('', t('Sort'), t('Title'), t('Subtitle'), t('Query')));
  $rows[] = $configs;
  $form['ding_redia_carousels']['table'] = array(
    '#theme' => 'table',
    '#header' =>  array(
      array('data' => t('Carousel')),
      array('data' => t('Configurations'), 'colspan' => 4),
    ),
    '#rows' => $configs,
  );
  $form_state['ding_redia_carousels'] = $configs;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('ding_redia_variables_admin_form_submit'),
  );

  return $form;
}

/**
 * Add drupal variable in the redia array.
 */
function ding_redia_variables_add($form, &$form_state) {
  $variable = $form_state['values']['ding_redia_variables']['variable'];
  $value = variable_get($variable, '');
  $form_state['ding_redia_variables'][] = array($variable, $value);

  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback on submit.
 */
function ding_redia_variables_ajax_callback($form, &$form_state) {
  return $form['ding_redia_variables'];
}



/**
 * Save configurations into a single variable.
 */
function ding_redia_variables_admin_form_submit($form, &$form_state) {
  variable_set('ding_redia_variables', $form_state['ding_redia_variables']);
  variable_set('ding_redia_carousels', $form_state['ding_redia_carousels']);
}
