# Store Locator
Drupal module Store Locator is based on Views and Google Maps API.

Store Locator module uses the next modules: ctools, views, views_load_more, addressfield, entity, geocoder, geofield, 
geophp, office_hours.

It's not required Google Store Locator library or Google Store Locator drupal module. I changed code so you can test
Store Locator module with Google Store Locator module on one site.
 
Page with map has path (Google Store Locator module has /store-locator by default):
/office-locator

# Demo
http://store-locator.contrib.coldbrainweb.com/office-locator?field_geofield_distance%5Borigin%5D=90210


# Installation

Simply drop the module into the Drupal sites/all/modules folder or the
sites/<mysite>/modules folder and activate via the admin/build/modules UI as 
normal.

Settings:

Navigate to /admin/config/search/office_locator map settings. You can set default map center, zoom and custom marker 
icon.

Usage:

Navigate to /office-locator to see store locator map.

# Features
Store locator map is displayed through Google Maps. You must add Office Location nodes to display them on the map.
User can choose his locator using autocomplete or HTML5 geolocaton. It's displayed 5 the nearest stores (offices) and
show more 5 offices button with AJAX.
Store information includes office hours with open/close info.

It's not support Location Awareness, but I am working on it using AJAX.
