(function ($) {
  Drupal.behaviors.storeLocatorMap = {
    attach: function (context, settings) {
      // Geolocation from browser.
      $('.view-map .views-exposed-form .description').once('click').click(function() {
        if (navigator.geolocation) {
          navigator.geolocation.getCurrentPosition(function(position) {
            $('.geofield-proximity-origin').val(position.coords.latitude + ',' + position.coords.longitude);
            $('#edit-submit-store-locator').click();
          });
        }
        else {
          // Show message about geolocation access denied.
        }
      });

      // Check if map class exist.
      if ($('.header-map').length) {
        // Init map.
        var directionsService = new google.maps.DirectionsService();
        var directionsDisplay = new google.maps.DirectionsRenderer();
        $('.header-map').once('storeLocatorMap', function() {
          var $this = $(this);

          var myOptions = {
            zoom: 10,
            mapTypeId: 'roadmap',
            mapTypeControl: true,
            mapTypeControlOptions: {style: 1},
            zoomControl: true,
            zoomControlOptions: {style: 0},
            panControl: true,
            scrollwheel: false,
            draggable: true,
            overviewMapControl: false,
            overviewMapControlOptions: {opened: false},
            streetViewControl: false,
            scaleControl: false,
            scaleControlOptions: {style: 0},
            disableDefaultUI: true
          };

          var map = new google.maps.Map(document.getElementById('map'), myOptions);

          map.setCenter(new google.maps.LatLng(Drupal.settings.storeLocatorMap.latitude, Drupal.settings.storeLocatorMap.longitude));

          map.bounds = new google.maps.LatLngBounds();

          // Save map to global drupal settings.
          Drupal.settings.storeLocatorMap.map = map;

          // Set directions on map.
          directionsDisplay.setMap(Drupal.settings.storeLocatorMap.map);
          // set directions description on panel.
          directionsDisplay.setPanel(document.getElementById('directionsPanel'));

          var input = (document.getElementById('edit-field-geofield-distance-origin'));
          var autocomplete = new google.maps.places.Autocomplete(input);
          autocomplete.bindTo('bounds', map);

          autocomplete.addListener('place_changed', function() {
            infowindow.close();
            marker.setVisible(false);
            var place = autocomplete.getPlace();
            if (!place.geometry) {
              window.alert("Autocomplete's returned place contains no geometry");
              return;
            }

            // If the place has a geometry, then present it on a map.
            if (place.geometry.viewport) {
              map.fitBounds(place.geometry.viewport);
            } else {
              map.setCenter(place.geometry.location);
              map.setZoom(17);  // Why 17? Because it looks good.
            }
            marker.setIcon(/** @type {google.maps.Icon} */({
              url: place.icon,
              size: new google.maps.Size(71, 71),
              origin: new google.maps.Point(0, 0),
              anchor: new google.maps.Point(17, 34),
              scaledSize: new google.maps.Size(35, 35)
            }));
            marker.setPosition(place.geometry.location);
            marker.setVisible(true);

            var address = '';
            if (place.address_components) {
              address = [
                (place.address_components[0] && place.address_components[0].short_name || ''),
                (place.address_components[1] && place.address_components[1].short_name || ''),
                (place.address_components[2] && place.address_components[2].short_name || '')
              ].join(' ');
            }

            infowindow.setContent('<div><strong>' + place.name + '</strong><br>' + address);
            infowindow.open(map, marker);
          });

        });

        // Add event listener for show directions by click.
        $('.get-directions').once('click').click(function(e) {
          e.stopPropagation();
          calculateAndDisplayRoute(directionsService, directionsDisplay, this);
        });

        // Add only new markers on the map. view-map class is set in CSS class Drupal.settings.
        if ((context == document || $(context).hasClass('view-map'))) {
          if (!Drupal.settings.storeLocatorMap.page) {
            if (Drupal.settings.storeLocatorMap.markers) {
              for (var i = 0; i < Drupal.settings.storeLocatorMap.markers.length; i++) {
                Drupal.settings.storeLocatorMap.markers[i].setMap(null);
              }
              Drupal.settings.storeLocatorMap.map.bounds = new google.maps.LatLngBounds();
            }
            Drupal.settings.storeLocatorMap.markers = [];
          }
          Drupal.settings.storeLocatorMap.info = [];

          if (typeof Drupal.settings.storeLocatorMap.coords != 'undefined') {
            $info = $('.view-map .location');

            // Collect data from each location.
            $.each(Drupal.settings.storeLocatorMap.coords, function (key, geo) {
              if (typeof geo.lat == 'undefined' || typeof geo.lon == 'undefined') {
                return;
              }
              // Get current pager number.
              var pageKey = key + (parseInt(Drupal.settings.storeLocatorMap.page) * Drupal.settings.storeLocatorMap.count);
              var position = new google.maps.LatLng(parseFloat(geo.lat), parseFloat(geo.lon));
              var marker = new google.maps.Marker({
                position: position,
                map: Drupal.settings.storeLocatorMap.map,
                title: 'Our Store',
                key: pageKey,
                icon: Drupal.settings.storeLocatorMap.icon
              });

              // Add new markers on the map.
              Drupal.settings.storeLocatorMap.map.bounds.extend(marker.position);

              // Copy html from location views-row to marker popup.
              marker.info = new google.maps.InfoWindow({
                content: $info.eq(pageKey).clone(true).removeClass('location')[0]
              });

              // Click trigger.
              marker.addListener('click', function () {
                // Close all popups.
                for (var i = 0; i < Drupal.settings.storeLocatorMap.markers.length; i++) {
                  Drupal.settings.storeLocatorMap.markers[i].info.close();
                }
                // Open popup for this marker.
                this.info.open(Drupal.settings.storeLocatorMap.map, this);

                // Remove all selected classes from location lists
                $('.location').removeClass('selected');
                // Add class for location which one is selected on the map.
                $('.location').eq(this.key).addClass('selected');
              });

              $('.location').once('click').click(function () {
                for (var i = 0; i < Drupal.settings.storeLocatorMap.markers.length; i++) {
                  Drupal.settings.storeLocatorMap.markers[i].info.close();
                }

                // Open popup for this marker.
                var key = $(this).index();
                var balloon = Drupal.settings.storeLocatorMap.markers[key];
                balloon.info.open(Drupal.settings.storeLocatorMap.map, balloon);
                // Scroll to map.
                $('html, body').animate({
                  scrollTop: $('#map').offset().top - 120
                }, 500);

                // Remove all selected classes from location lists
                $('.location').removeClass('selected');
                // Add class for location which one is selected on the map.
                $(this).addClass('selected');
              });

              // Add new markers to Drupal.settings variable.
              Drupal.settings.storeLocatorMap.markers[pageKey] = marker;
            });

            // Zoom map to see all markers.
            Drupal.settings.storeLocatorMap.map.fitBounds(Drupal.settings.storeLocatorMap.map.bounds);
          }
        }
      }
    }
  };

  // Show directions on the map.
  function calculateAndDisplayRoute(directionsService, directionsDisplay, link) {
    if ((navigator.platform.indexOf('iPhone') != -1)
      || (navigator.platform.indexOf('iPod') != -1)
      || (navigator.platform.indexOf('iPad') != -1)) {
      // Open iOS maps application.
      window.open('maps://maps.google.com/maps?daddr=' + $(link).attr('data-lat') + ',' + $(link).attr('data-long') + '&amp;ll=');
    }
    else {
      // Show directions below map.
      var userLat;
      var userLong;
      var originCoords;
      if (Drupal.settings.storeLocatorMap.latitude !== undefined &&
        Drupal.settings.storeLocatorMap.longitude !== undefined) {
        userLat = Drupal.settings.storeLocatorMap.latitude;
        userLong = Drupal.settings.storeLocatorMap.longitude;
      }
      originCoords = new google.maps.LatLng(parseFloat(userLat), parseFloat(userLong));
      var destinationCoords = new google.maps.LatLng(parseFloat($(link).attr('data-lat')), parseFloat($(link).attr('data-long')));
      // For more infomation, see https://developers.google.com/maps/documentation/javascript/directions?hl=ru page.
      var request = {
        origin: originCoords,
        destination: destinationCoords,
        travelMode: google.maps.TravelMode.DRIVING
      };
      directionsService.route(request, function (result, status) {
        if (status == google.maps.DirectionsStatus.OK) {
          directionsDisplay.setDirections(result);
        }
      });
    }
  }
}(jQuery));