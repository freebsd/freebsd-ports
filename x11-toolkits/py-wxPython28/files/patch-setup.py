--- ./setup.py.orig	Mon Nov 26 19:05:40 2007
+++ ./setup.py	Thu Dec 20 21:05:46 2007
@@ -776,6 +776,7 @@
 
     wxpExtensions.append(ext)
 
+EXTRA_PATH = getExtraPath(addOpts=EP_ADD_OPTS)
 
 
     
