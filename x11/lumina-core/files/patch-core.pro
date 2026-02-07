--- core.pro.orig	2021-12-26 02:33:45 UTC
+++ core.pro
@@ -4,14 +4,16 @@ include("../OS-detect.pri")
 TEMPLATE = subdirs
 CONFIG += recursive
 
+# lumina-checkpass is needed for 1.6.2, since code replacing
+# xscreensaver is enabled
 SUBDIRS+= lumina-desktop \
 	lumina-session \
 	lumina-open \
 	lumina-info \
 	lumina-pingcursor \
 	$${PWD}/../../icon-theme \
-	lumina-theme-engine 
-#	lumina-checkpass
+	lumina-theme-engine \
+	lumina-checkpass
 #	lumina-desktop-unified
 
 #Also install any special menu scripts
