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
1. Download a compiled version of the akamai open video player [here](http://caryme.com/files/AkamaiMultiPlayerExample.swf "Right click and save as")
2. Download swfobject 2.2 from google code [here](http://code.google.com/p/swfobject/)
3. Put the open video player at /sites/all/libraries/ovp/AkamaiMultiPlayerExample.swf
4. Move swfobject.js to /sites/all/libraries/swfobject/swfobject.js

Usage
=====
Main streaming video module
---------------------------
The streaming video format is: [ovp:uri] where uri is a valid streaming video resource.
