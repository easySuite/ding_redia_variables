<?php
/**
 * @file
 * ding_redia_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ding_redia_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ding_redia_carousels';
  $strongarm->value = array(
    0 => array(
      'name' => 'carousel',
      'configs' => array(
        0 => array(
          'sort' => '0',
          'title' => '',
          'subtitle' => '',
          'query' => '',
        ),
      ),
    ),
    1 => array(
      'name' => 'ding_item_viewer',
      'configs' => array(
        0 => array(
          'sort' => 0,
          'title' => '',
          'subtitle' => '',
          'query' => '',
        ),
      ),
    ),
  );
  $export['ding_redia_carousels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ding_redia_variables';
  $strongarm->value = array(
    0 => array(
      0 => 'ting_agency',
      1 => '786000',
    ),
    1 => array(
      0 => 'ting_search_profile',
      1 => 'HJOIND',
    ),
    2 => array(
      0 => 'ting_boost_fields',
      1 => array(
        0 => array(
          'field_name' => 'term.acSource',
          'field_value' => 'bibliotekskatalog',
          'weight' => '10000',
        ),
        1 => array(
          'field_name' => 'term.language',
          'field_value' => 'dansk',
          'weight' => '500',
        ),
      ),
    ),
    3 => array(
      0 => 'ting_ranking_fields',
      1 => array(
        0 => array(
          'field_type' => 'word',
          'field_name' => 'term.title',
          'weight' => '3',
        ),
        1 => array(
          'field_type' => 'phrase',
          'field_name' => 'term.acSource',
          'weight' => '1',
        ),
      ),
    ),
    4 => array(
      0 => 'ting_ranking_custom',
      1 => 1,
    ),
    5 => array(
      0 => 'ting_sort_default',
      1 => 'rank_frequency',
    ),
    6 => array(
      0 => 'ting_search_results_per_page',
      1 => '10',
    ),
    7 => array(
      0 => 'ting_search_result_message_limit',
      1 => '100',
    ),
    8 => array(
      0 => 'dibs_settings_ding_dibs_1',
      1 => array(
        'general' => array(
          'merchant' => '2$13123',
          'account' => '12312',
          'test_mode' => '0',
          'type' => 'flex',
          'retry_handling' => 'add_retry_suffix',
          'md5' => '0',
          'md5_key1' => 'sadsadas',
          'md5_key2' => 'dasdas',
          'lang' => 'no',
          'currency' => '978',
        ),
        'paymentwindow' => array(
          'color' => 'sand',
        ),
        'flexwindow' => array(
          'color' => 'blue',
          'decorator' => 'rich',
          'voucher' => '0',
        ),
        'advanced' => array(
          'calcfee' => '1',
          'capturenow' => '0',
          'unqiue_order_id' => '1',
        ),
        'callbacks' => array(
          'accepturl' => 'payment/dibs/accept',
          'cancelurl' => 'payment/dibs/cancel',
          'callbackok' => 'payment/dibs/callbackok',
        ),
      ),
    ),
    9 => array(
      0 => 'ting_search_url',
      1 => 'http://opensearch.addi.dk/4.0.1/',
    ),
  );
  $export['ding_redia_variables'] = $strongarm;

  return $export;
}
