--- kdm/kfrontend/genkdmconf.c.orig	Mon Jun  5 14:34:06 2006
+++ kdm/kfrontend/genkdmconf.c	Mon Jun  5 14:35:52 2006
@@ -1684,7 +1684,7 @@
 		linkfile( ce );
 	else {
 		tmpf = locate( "mktemp" ) ?
-		           "`mktemp`" :
+		           "`mktemp /tmp/xsess-env-XXXXXX`" :
 		           locate( "tempfile" ) ?
 		               "`tempfile`" :
 		               "$HOME/.xsession-env-$DISPLAY";
