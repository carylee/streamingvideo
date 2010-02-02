/* $Id: README.txt,v 1.3 2009/06/10 19:53:53 jenlampton Exp $ */

-- SUMMARY --

The 'template' plugin for TinyMCE allows a user to select a HTML template from a drop-down and insert it into the WYSIWYG text-area.  This module supports that TinyMCE plugin for use with the WYSIWYG API, but of course, if anyone wanted to provide additions for FCK or other editors I'll be happy to include those too.  

For a full description visit the project page:
  http://drupal.org/project/wysiwyg_template
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/wysiwyg_template


-- REQUIREMENTS --

* Wysiwyg API


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.

* Go to Administer > Site configuration > Wysiwyg Template, and verify the values
  for your path and file name of your template registry file  (this file will 
  hold the names and locations of your templates)

* Create the template registry file in the specified location, its contents should
  look something like this: 
  
  // These templates will be displayed as a dropdown
  var tinyMCETemplateList = [
  // Name, URL, Description
  ["Template One", "sites/all/files/templates/template1.html", "Template One"],
  ["Template Two", "sites/all/files/templates/template2.html", "Template Two"]
  ];
  
*  Create your template files at the locations specified in your registry file

-- CONFIGURATION --

* Go to Administer > Site configuration > Wysiwyg and

  - click "edit" to set up your editor profile

  - under "Buttons and Plugins" you'll see "Insert Templates" as a new option

