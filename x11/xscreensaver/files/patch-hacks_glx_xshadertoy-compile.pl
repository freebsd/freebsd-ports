--- hacks/glx/xshadertoy-compile.pl.orig	2026-01-22 14:18:32 UTC
+++ hacks/glx/xshadertoy-compile.pl
@@ -85,7 +85,7 @@ sub compile($@) {
   $title =~ s@^.*/@@gs;
 
   my $year = (localtime)[5] + 1900;
-  my $head = '#!/bin/bash
+  my $head = '#!/bin/sh
 # XScreenSaver, Copyright © ' . $year . ' Jamie Zawinski <jwz@jwz.org>
 #
 # Permission to use, copy, modify, distribute, and sell this software and its
@@ -97,8 +97,7 @@ PATH="$PATH":"$(dirname "$0")"
 # implied warranty.
 
 PATH="$PATH":"$(dirname "$0")"
-exec -a "' . $title . '" \
-xshadertoy "$@" \
+exec xshadertoy "$@" \
 ';
 
   $head .= " --program-common - \\\n" if (defined ($common));
