<?php

/**
 * @file
 * Pages.
 */

/**
 * Hierarchy page.
 */
function usptobdss_hierarchy_page() {
  $h = usptobdss_hierarchy_load();

  $output = '<h2>IP Types</h2>';

  $output .= '<ul>';

  foreach ($h as $parent) {
    $output .= '<li><a href="bdss/' . strtolower($parent->productTitle) . '">' . $parent->productTitle . '</a></li>';
  }

  $output .= '</ul>';

  $output .= '<h2>Misc</h2>';
  $output .= '<ul>';
  $output .= '<li><a href="bdss/popular">Popular Products</a></li>';
  $output .= '</ul>';

  return $output;
}

/**
 * Popular page.
 */
function usptobdss_popular_page() {
  $output = '';

  $r = new usptobdssRequest;

  foreach (usptobdss_popular_load() as $p) {
    $output .= '<h3><a href="' . $r->url . $p->productLinkPath . '">' . $p->productTitle . '</a></h3>';
    $output .= '<p>Latest release: ' . $p->productFiles[0]->fileName . ' | ' . $p->productFiles[0]->fileReleaseDate . '</p>';
    $output .= '
      <div class="btn btn-primary btnprmy">
        <a href="' . $p->productFiles[0]->fileDownloadUrl . '"><i class="fa fa-download"></i> Download latest (' . $p->productFiles[0]->fileSize . ')</a>
      </div>';
  }

  return $output;
}

/**
 * Patent page.
 */
function usptobdss_patent_page() {
  $h = usptobdss_hierarchy_load();

  $output = '<ul>';

  foreach ($h as $parent) {
    if ($parent->productShortName == 'PTNT') {
      $output .= '<li><a href="bdss/' . $parent->productShortName . '">' . $parent->productTitle . '</a></li>';
    }
  }

  $output .= '</ul>';

  return $output;
}

/**
 * Trademark page.
 */
function usptobdss_trademark_page() {
  $h = usptobdss_hierarchy_load();

  $output = '<ul>';

  foreach ($h as $parent) {
    $output .= '<li><a href="bdss/' . $parent->productShortName . '">' . $parent->productTitle . '</a></li>';
  }

  $output .= '</ul>';

  return $output;
}

