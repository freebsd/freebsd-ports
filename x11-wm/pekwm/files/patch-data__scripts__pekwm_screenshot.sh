--- data/scripts/pekwm_screenshot.sh.orig	2013-05-24 19:24:23 UTC
+++ data/scripts/pekwm_screenshot.sh
@@ -1,30 +1,30 @@
-#!/usr/bin/env bash
+#!/bin/sh
 #
 # Copyright © 2013 the pekwm development team
 #
 
-function screenshot_scrot
+screenshot_scrot()
 {
     scrot -z "$1"
 }
 
-function screenshot_xwd_netpbm
+screenshot_xwd_netpbm()
 {
     xwd -root | xwdtopnm 2>/dev/null | pnmtopng > "$1"
 }
 
-function screenshot_imagemagick
+screenshot_imagemagick()
 {
     import -window root "$1"
 }
 
-function is_in_path
+is_in_path()
 {
     which $1 >/dev/null 2>&1
     return $?
 }
 
-function detect_command
+detect_command()
 {
     is_in_path "scrot"
     if test $? -eq 0; then
@@ -45,7 +45,7 @@ function detect_command
     fi
 }
 
-function usage
+usage()
 {
     echo "usage: pekwm_screenshot.sh [-c scrot|netpbm|magick] [-d delay] [-o output.png]"
     echo ""
@@ -61,7 +61,7 @@ function usage
     exit 0
 }
 
-function usage_command
+usage_command()
 {
     echo "Unable to find any supported commands for taking screenshots"
     echo ""
@@ -74,7 +74,7 @@ function usage_command
     exit 1
 }
 
-function main
+main()
 {
     # Initialize for strict mode
     command=""
