<?php
/**
 * @file
 * import_settings.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function import_settings_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'opencart';
  $feeds_importer->config = array(
    'name' => 'Opencart',
    'description' => 'Get products from opencart CSV',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Product Name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Image',
            'target' => 'uc_product_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Catalog',
            'target' => 'taxonomy_catalog',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'SKU',
            'target' => 'model',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Sell Price',
            'target' => 'sell_price',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['opencart'] = $feeds_importer;

  return $export;
}
