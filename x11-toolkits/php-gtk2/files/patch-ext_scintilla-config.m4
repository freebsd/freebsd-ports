--- ext/scintilla/config.m4.orig	Thu Jul 10 23:05:44 2003
+++ ext/scintilla/config.m4	Thu Jul 10 23:05:52 2003
@@ -6,10 +6,10 @@
   --enable-scintilla      Enable Scintilla support])
 
 if test "$PHP_GTK_SCINTILLA" != "no"; then
-  for x in /usr /usr/local; do
-	  if test -f $x/include/gtkscintilla.h; then
+  for x in /usr/include /usr/local/include /usr/X11R6/include/scintilla; do
+	  if test -f $x/gtkscintilla.h; then
 		  SCINTILLA_DIR=$x
-		  SCINTILLA_INCDIR=$x/include
+		  SCINTILLA_INCDIR=$x
 	  fi
   done
 
