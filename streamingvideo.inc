<?php
// $Id$

function streamingvideo_embedcode( $src, $withhtml=false ) {
  $player = base_path() . "sites/all/libraries/ovp/AkamaiMultiPlayerExample.swf";

  // Load the variables
  $width = variable_get('streamingvideo_width', 640);
  $height = variable_get('streamingvideo_height', 480);
  $autostart = variable_get('streamingvideo_autostart', 'false');
  $mode = variable_get('streamingvideo_mode', 'sidebyside');
  // options: sidebyside or overlay
  $themecolor = variable_get('streamingvideo_themecolor', '0395d3');
  $allowfullscreen = variable_get('streamingvideo_allowfullscreen', 'true');
  $scalemode = variable_get('streamingvideo_scalemode', 'fit');
  // options: fit, stretch, native, nativeorsmaller

  $src_encoded = urlencode($src);

  $embed = "
    var flashvars = { 
      src: \"$src_encoded\", 
      autostart: \"$autostart\", 
      themeColor: \"$themecolor\", 
      mode: \"$mode\", 
      scaleMode: \"$scalemode\" 
    }; 
    var params = {}; 
      var attributes = { 
      id: \"myPlayer\", 
      name: \"myPlayer\", 
      allowFullScreen: \"$allowfullscreen\" 
    }; 
    swfobject.embedSWF(\"$player\", 'myPlayerGoesHere', '$width', '$height', '9.0.0', 'expressInstall.swf', flashvars, params, attributes);";

  if( $withhtml ) {
    $embed = "<script type='text/javascript'>$embed</script><div id='myPlayerGoesHere'><a href='http://www.adobe.com/go/getflashplayer'><img src='http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif' alt='Get Adobe Flash player' /></a></div>";
  }

  return $embed;
}
