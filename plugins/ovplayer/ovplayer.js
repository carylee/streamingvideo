// $Id$

Drupal.wysiwyg.plugins['ovplayer'] = {

  invoke: function(data, settings, instanceId) {
      
      var optionString = "\"dialogWidth:" + settings.dialog.width + "px;dialogHeight:" + settings.dialog.height + "px;\"";
      var videoValue = window.showModalDialog(settings.dialog.url, "", optionString);
      var videoUrl = videoValue[0];
      var videoHeight = videoValue[1];
      var videoWidth = videoValue[2];

      if( videoUrl ) {
        var ovpString = "[ovp:";
        if( videoHeight ) {
          ovpString += "height=" + videoHeight + ",";
        }
        if( videoWidth ) {
          ovpString += "width=" + videoWidth + ",";
        }

        ovpString += videoUrl + "]";
        Drupal.wysiwyg.instances[instanceId].insert(ovpString);
      }
  },
