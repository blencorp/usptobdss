<?php

/**
 * @file
 *
 * Request objects for USPTO BDSS API.
 */

class usptobdssRequest {
  public $url;
  public $params = array();

  static function factory($type) {
    switch ($type) {
      case 'hierarchy':
        return new usptobdssRequestHierarchy();
      case 'popular':
        return new usptobdssRequestPopular();
      case 'ipTypes':
        return new usptobdssRequestIPTypes();
      case 'dataTypes':
        return new usptobdssRequestDataTypes();
      case 'productCategories':
        return new usptobdssRequestProductCategories();
      case 'productTypes':
        return new usptobdssRequestProductTypes();
      case 'products':
        return new usptobdssRequestProducts();
      case 'productFiles':
        return new usptobdssRequestProductFiles();
    }
  }

  function __construct() {
    $this->url = 'https://' . variable_get('usptobdss_url', 'bulkdata.uspto.gov/BDSS-API');
  }

  public function request() {
    $url = $this->url;
    $data = $this->_request($url);
    return $data;
  }

  protected function _request($url) {
    $response = drupal_http_request($url);

    if ($response->code == '200') {
      $data = json_decode($response->data);
      return $data;
    } else {
      watchdog('error', 'HTTP error !code received', array('!code' => $response->code));
    }
    return FALSE;
  }
}

class usptobdssRequestHierarchy extends usptobdssRequest {
  public function request() {
    $this->url .= '/products/tree';
    $result = parent::request();
    return $result;
  }
}

class usptobdssRequestPopular extends usptobdssRequest {
  public function request() {
    $this->url .= '/products/popular';
    $result = parent::request();
    return $result;
  }
}

class usptobdssRequestIPTypes extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

class usptobdssRequestDataTypes extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

class usptobdssRequestProductCategories extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

class usptobdssRequestProductTypes extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

class usptobdssRequestProducts extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

class usptobdssRequestProductFiles extends usptobdssRequest {
  public function request() {
    $items = array();
    return $items;
  }
}

