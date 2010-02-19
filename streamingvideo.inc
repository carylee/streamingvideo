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

function streamingvideo_extracturi( $ovpstring ) {
  $pattern = "/(http|rtmp|rtmpt|rtmpe|rtmpte):\/\/([\d\w$\-.+!*'\"():\/.?&=]*)/";
  if( preg_match( $pattern, $ovpstring, $matches ) ){
    return $matches[0];
  }
  else
    return false;
}

function streamingvideo_parseoptions( $ovpstring ) {
  $options = array();
  if( preg_match( '/width=(\d+),/', $ovpstring, $widthMatches ) )
    $options['width'] = $widthMatches[1];

  if( preg_match( '/height=(\d+),/', $ovpstring, $heightMatches) )
    $options['height'] = $heightMatches[1];

  if( preg_match( '/allowfullscreen=(true|false),/', $ovpstring, $fullscreenMatches ) )
    $options['allowfullscreen'] = $fullscreenMatches[1];

  if( preg_match( '/autostart=(true|false),/', $ovpstring, $autostart ) )
    $options['autostart'] = $autostart[1];

  if( preg_match( '/scalemode=(fit|stretch|native|nativeorsmaller),/', $ovpstring, $scalemode))
    $options['scalemode'] = $scalemode[1];

  if( preg_match( '/mode=(sidebyside|overlay),/', $ovpstring, $mode ))
    $options['mode'] = $mode[1];

  if( preg_match( '/themecolor=([0-9a-fA-F]{6}),/', $ovpstring, $themecolor))
    $options['themecolor'] = $themecolor[1];

  return $options;
}

function streamingvideo_external_embed( $url ) {
  $default_player_url = url(NULL, array('absolute'=>TRUE)) . 'sites/all/libraries/ovp/AkamaiMultiPlayerExample.swf';
  $player_url = variable_get('streamingvideo_embedplayer', $default_player_url);
  $src = $player_url . '?src=' . urlencode( $url ) . '&autostart=true&themeColor=0395d3&mode=sidebyside&scaleMode=fit';

  
  $code = '<object width="425" height="344"><embed src="' . $src . '" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="425" height="344"></embed></object>';
          
  return $code;
}

function streamingvideo_embedtext( $url ) {
  $text = streamingvideo_external_embed( $url );
  return '<textarea>' . $text . '</textarea>';
}
