Name
====
Streaming video

Requirements
============
This module requires Drupal 6.X
The submodule streamingvideofield requires CCK

Description
===========
The streaming video module uses the Akamai Open Video Player to play video of many types, specializing in flash video streams.

Streaming video module
----------------
The main streamingvideo module defines an input filter that allows a formatted string to be replaced with a video player.

Streaming video field module
----------------------------
The streamingvideofield module defines a CCK field and a formatter. This allows the addition of a streaming video URI to content types which can be presented as video using the Akaamai Open Video Player.

Installation
============
1. Download a compiled version of the akamai open video player http://caryme.com/files/AkamaiMultiPlayerExample.swf
2. Download swfobject 2.2 from google code http://code.google.com/p/swfobject/
3. Put the open video player at /sites/all/libraries/ovp/AkamaiMultiPlayerExample.swf
4. Move swfobject.js to /sites/all/libraries/swfobject/swfobject.js

Usage
=====
Main streaming video module
---------------------------
The streaming video format is: [ovp:option=value,option=value,uri] where uri is a valid streaming video resource.
The options can be any of the following:
width (number in pixels)
height (number in pixels)
themecolor (6-character hexidecimal color code)
autostart (true or false)
allowfullscreen (true or false)
scalemode (fit, stretch, native, or nativeorsmaller)
mode (sidebyside or overlay)

These options may be presented in any order

When options are left undefined, they will default to the global settings which can be changed at admin/settings/streamingvideo

CCK Field
---------
For the CCK field, player options can be set one of two ways.  Player options can be set for an entire content type on the "manage fields" page for the Streaming video widget.  When these settings are omitted, they default to the global settings.  Player options can be set directly for a single node using same synatax as the filter excluding the [ovp:] wrapper (so option=value,option=value, uri).  These sort of settings have precidence over the content type-level settings.
