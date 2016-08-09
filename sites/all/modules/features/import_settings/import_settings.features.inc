<?php
/**
 * @file
 * import_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function import_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
