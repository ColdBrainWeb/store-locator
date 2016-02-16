<?php
/**
 * @file
 * store_locator.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function store_locator_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'store_locator';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Store Locator';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Store Locator';
  $handler->display->display_options['css_class'] = 'view-map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Find store';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Next 5 locations';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'location';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="header-map">
  <div class="view-content">
    <div id="map" class="geofieldMap"></div>
  </div>
  <div id="directionsPanel"></div>
</div>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div id="no-result-map"></div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Store Locator Address */
  $handler->display->display_options['fields']['sl_addressfield']['id'] = 'sl_addressfield';
  $handler->display->display_options['fields']['sl_addressfield']['table'] = 'field_data_sl_addressfield';
  $handler->display->display_options['fields']['sl_addressfield']['field'] = 'sl_addressfield';
  $handler->display->display_options['fields']['sl_addressfield']['label'] = '';
  $handler->display->display_options['fields']['sl_addressfield']['element_type'] = '0';
  $handler->display->display_options['fields']['sl_addressfield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_addressfield']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['sl_addressfield']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_addressfield']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['sl_addressfield']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['sl_addressfield']['field_api_classes'] = TRUE;
  /* Field: Content: Store Hours */
  $handler->display->display_options['fields']['field_store_hours']['id'] = 'field_store_hours';
  $handler->display->display_options['fields']['field_store_hours']['table'] = 'field_data_field_store_hours';
  $handler->display->display_options['fields']['field_store_hours']['field'] = 'field_store_hours';
  $handler->display->display_options['fields']['field_store_hours']['label'] = '';
  $handler->display->display_options['fields']['field_store_hours']['element_type'] = '0';
  $handler->display->display_options['fields']['field_store_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_store_hours']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_store_hours']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_store_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_store_hours']['settings'] = array(
    'showclosed' => 'open',
    'date_first_day' => '1',
    'daysformat' => 'short',
    'hoursformat' => '1',
    'compress' => 1,
    'grouped' => 1,
    'closedformat' => 'Closed',
    'separator_days' => '<br />',
    'separator_grouped_days' => ' - ',
    'separator_day_hours' => ': ',
    'separator_hours_hours' => '-',
    'separator_more_hours' => ', ',
    'current_status' => array(
      'position' => 'after',
      'open_text' => 'OPEN',
      'closed_text' => 'CLOSED',
    ),
  );
  $handler->display->display_options['fields']['field_store_hours']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_store_hours']['field_api_classes'] = TRUE;
  /* Field: Content: Misc. Properties */
  $handler->display->display_options['fields']['sl_props_misc']['id'] = 'sl_props_misc';
  $handler->display->display_options['fields']['sl_props_misc']['table'] = 'field_data_sl_props_misc';
  $handler->display->display_options['fields']['sl_props_misc']['field'] = 'sl_props_misc';
  $handler->display->display_options['fields']['sl_props_misc']['label'] = '';
  $handler->display->display_options['fields']['sl_props_misc']['element_type'] = '0';
  $handler->display->display_options['fields']['sl_props_misc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_props_misc']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['sl_props_misc']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_props_misc']['field_api_classes'] = TRUE;
  /* Field: Content: Store Phone */
  $handler->display->display_options['fields']['sl_props_phone']['id'] = 'sl_props_phone';
  $handler->display->display_options['fields']['sl_props_phone']['table'] = 'field_data_sl_props_phone';
  $handler->display->display_options['fields']['sl_props_phone']['field'] = 'sl_props_phone';
  $handler->display->display_options['fields']['sl_props_phone']['label'] = '';
  $handler->display->display_options['fields']['sl_props_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['sl_props_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_props_phone']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['sl_props_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_props_phone']['field_api_classes'] = TRUE;
  /* Field: Content: Store Website */
  $handler->display->display_options['fields']['sl_props_web']['id'] = 'sl_props_web';
  $handler->display->display_options['fields']['sl_props_web']['table'] = 'field_data_sl_props_web';
  $handler->display->display_options['fields']['sl_props_web']['field'] = 'sl_props_web';
  $handler->display->display_options['fields']['sl_props_web']['label'] = '';
  $handler->display->display_options['fields']['sl_props_web']['element_type'] = '0';
  $handler->display->display_options['fields']['sl_props_web']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_props_web']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['sl_props_web']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_props_web']['field_api_classes'] = TRUE;
  /* Field: Content: Store Locator Geofield (sl_geofield) - proximity */
  $handler->display->display_options['fields']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['label'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_geofield_distance']['element_class'] = 'proximity';
  $handler->display->display_options['fields']['field_geofield_distance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geofield_distance']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_geofield_distance']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_distance']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_distance']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_distance']['precision'] = '1';
  $handler->display->display_options['fields']['field_geofield_distance']['separator'] = '';
  $handler->display->display_options['fields']['field_geofield_distance']['suffix'] = ' mi';
  $handler->display->display_options['fields']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'sl_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'sl_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['radius_of_earth'] = '3959';
  /* Field: Content: Store Locator Geofield */
  $handler->display->display_options['fields']['sl_geofield']['id'] = 'sl_geofield';
  $handler->display->display_options['fields']['sl_geofield']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['fields']['sl_geofield']['field'] = 'sl_geofield';
  $handler->display->display_options['fields']['sl_geofield']['label'] = '';
  $handler->display->display_options['fields']['sl_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sl_geofield']['element_type'] = '0';
  $handler->display->display_options['fields']['sl_geofield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_geofield']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['sl_geofield']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['sl_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['sl_geofield']['field_api_classes'] = TRUE;
  /* Field: Content: Store Locator Geofield */
  $handler->display->display_options['fields']['sl_geofield_1']['id'] = 'sl_geofield_1';
  $handler->display->display_options['fields']['sl_geofield_1']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['fields']['sl_geofield_1']['field'] = 'sl_geofield';
  $handler->display->display_options['fields']['sl_geofield_1']['label'] = 'Geofield lat';
  $handler->display->display_options['fields']['sl_geofield_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sl_geofield_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['sl_geofield_1']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['sl_geofield_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Store Locator Geofield */
  $handler->display->display_options['fields']['sl_geofield_2']['id'] = 'sl_geofield_2';
  $handler->display->display_options['fields']['sl_geofield_2']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['fields']['sl_geofield_2']['field'] = 'sl_geofield';
  $handler->display->display_options['fields']['sl_geofield_2']['label'] = 'Geofield long';
  $handler->display->display_options['fields']['sl_geofield_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sl_geofield_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_geofield_2']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['sl_geofield_2']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['sl_geofield_2']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: phone-for-button-call */
  $handler->display->display_options['fields']['sl_props_phone_1']['id'] = 'sl_props_phone_1';
  $handler->display->display_options['fields']['sl_props_phone_1']['table'] = 'field_data_sl_props_phone';
  $handler->display->display_options['fields']['sl_props_phone_1']['field'] = 'sl_props_phone';
  $handler->display->display_options['fields']['sl_props_phone_1']['ui_name'] = 'phone-for-button-call';
  $handler->display->display_options['fields']['sl_props_phone_1']['label'] = '';
  $handler->display->display_options['fields']['sl_props_phone_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sl_props_phone_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['sl_props_phone_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['sl_props_phone_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sl_props_phone_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sl_props_phone_1']['type'] = 'text_plain';
  /* Field: Call-button */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Call-button';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<a href="tel:+1 [sl_props_phone_1]" class="mobile-only phone-call btn btn-primary">Call</a>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: get-directions-button */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'get-directions-button';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#map" class="get-directions" data-lat=\'[sl_geofield_1]\' data-long=\'[sl_geofield_2]\'><span class="desktop-only">Get </span>directions</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Store Locator Geofield (sl_geofield) - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'sl_geofield';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'sl_geofield';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'office_location' => 'office_location',
  );
  /* Filter criterion: Content: Store Locator Geofield (sl_geofield) - proximity */
  $handler->display->display_options['filters']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['table'] = 'field_data_sl_geofield';
  $handler->display->display_options['filters']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['operator'] = '<=';
  $handler->display->display_options['filters']['field_geofield_distance']['value'] = array(
    'distance' => '20',
    'distance2' => 200,
    'unit' => '3959',
    'origin' => '',
  );
  $handler->display->display_options['filters']['field_geofield_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator_id'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['label'] = 'Enter City or Zip code';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['identifier'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_geofield_distance']['source'] = 'geocoder';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'sl_geofield';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'sl_geofield';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'office-locator';
  $translatables['store_locator'] = array(
    t('Master'),
    t('Store Locator'),
    t('more'),
    t('Find store'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Next 5 locations'),
    t('<div class="header-map">
  <div class="view-content">
    <div id="map" class="geofieldMap"></div>
  </div>
  <div id="directionsPanel"></div>
</div>'),
    t('<div id="no-result-map"></div>'),
    t('.'),
    t(' mi'),
    t('Geofield lat'),
    t('Geofield long'),
    t('<a href="tel:+1 [sl_props_phone_1]" class="mobile-only phone-call btn btn-primary">Call</a>'),
    t('<a href="#map" class="get-directions" data-lat=\'[sl_geofield_1]\' data-long=\'[sl_geofield_2]\'><span class="desktop-only">Get </span>directions</a>'),
    t('Enter City or Zip code'),
    t('Page'),
  );
  $export['store_locator'] = $view;

  return $export;
}
