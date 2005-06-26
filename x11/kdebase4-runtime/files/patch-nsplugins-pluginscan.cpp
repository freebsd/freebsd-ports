--- nsplugins/pluginscan.cpp.orig	Sat Mar 13 21:07:58 2004
+++ nsplugins/pluginscan.cpp	Sat Mar 13 21:08:50 2004
@@ -457,6 +457,8 @@
 	paths.append("/usr/lib64/netscape/plugins");
 	paths.append("/usr/lib64/mozilla/plugins");
         paths.append("$MOZILLA_HOME/plugins");
+	paths.append("/usr/local/lib/linux-flashplugin6");
+	paths.append("/usr/X11R6/lib/linux-flashplugin6");
         config->writeEntry( "scanPaths", paths );
     }
 
