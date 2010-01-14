<?php
// $Id$

function streamingvideo_embedcode( $src, $options ) {
  $player = base_path() . "sites/all/libraries/ovp/AkamaiMultiPlayerExample.swf";

  // Load the variables
  if( empty($options['width'] ))
    $options['width'] = variable_get('streamingvideo_width', 640);

  if( empty($options['height'] ))
    $options['height'] = variable_get('streamingvideo_height', 480);

  if( empty($options['autostart'] ))
    $options['autostart'] = variable_get('streamingvideo_autostart', 'false');

  if( empty($options['mode'] ))
    $options['mode'] = variable_get('streamingvideo_mode', 'sidebyside');

  // options: sidebyside or overlay
  if( empty($options['themecolor'] ))
    $options['themecolor'] = variable_get('streamingvideo_themecolor', '0395d3');

  if( empty($options['allowfullscreen'] ))
    $options['allowfullscreen'] = variable_get('streamingvideo_allowfullscreen', 'true');

  if( empty($options['scalemode'] ))
    $options['scalemode'] = variable_get('streamingvideo_scalemode', 'fit');
  // options: fit, stretch, native, nativeorsmaller

  $src_encoded = urlencode($src);

  $embed = "
    var flashvars = { 
      src: \"$src_encoded\", 
      autostart: \"" . $options['autostart'] . "\", 
      themeColor: \"" . $options['themecolor'] . "\", 
      mode: \"" . $options['mode'] . "\", 
      scaleMode: \"" . $options['scalemode'] . "\" 
    }; 
    var params = {}; 
      var attributes = { 
      id: \"myPlayer\", 
      name: \"myPlayer\", 
      allowFullScreen: \"" . $options['allowfullscreen'] . "\" 
    }; 
    swfobject.embedSWF(\"$player\", 'myPlayerGoesHere', '" . $options['width'] . "', '" . $options['height'] . "', '9.0.0', 'expressInstall.swf', flashvars, params, attributes);";

  if( isset($options['html']) && $options['html']) {
    $embed = "<script type='text/javascript'>$embed</script><div id='myPlayerGoesHere'><a href='http://www.adobe.com/go/getflashplayer'><img src='http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif' alt='Get Adobe Flash player' /></a></div>";
  }

  return $embed;
}
