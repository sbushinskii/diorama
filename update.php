<?php

function custom_product_feeds_presave(FeedsSource $source, $entity, $item) {

    $entity->sell_price = $item['price'];
    $entity->list_price = $item['my_purchase_price'];
    $entity->cost = ($item['default_price']) ? $item['default_price'] : 0;
    $entity->model = $item['sku'];
    $entity->weight = $item['weight'];
    $entity->dim_length = $item['length'];
    $entity->dim_width = $item['width'];
    $entity->dim_height = $item['height'];
    $entity->title = $item['name'];
    $entity->description = $item['description'];

    test_category_exists($item['category_name']);
}

function test_category_exists($category_name) {
    $vocabulary = 'catalog';
    $arr_terms = taxonomy_get_term_by_name($category_name, $vocabulary);
    if (!empty($arr_terms)) {
        $arr_terms = array_values($arr_terms);
        $tid = $arr_terms[0]->tid;

    }
    else {
        $vobj = taxonomy_vocabulary_machine_name_load($vocabulary);
        $term = new stdClass();
        $term->name = $category_name;
        $term->vid = $vobj->vid;
        taxonomy_term_save($term);
        $tid = $term->tid;
    }
    return $tid;
}
