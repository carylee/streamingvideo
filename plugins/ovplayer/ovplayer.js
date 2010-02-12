// $Id: ovplayer.js,v 1.1 2009/08/24 20:48:05 joachim Exp $

Drupal.wysiwyg.plugins['ovplayer'] = {

  /**
   * Execute the button.
   */
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
};
