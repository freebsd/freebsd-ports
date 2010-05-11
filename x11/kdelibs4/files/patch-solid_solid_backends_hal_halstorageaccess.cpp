--- ./solid/solid/backends/hal/halstorageaccess.cpp.orig	2009-12-11 02:14:57.000000000 +0300
+++ ./solid/solid/backends/hal/halstorageaccess.cpp	2010-04-11 14:13:21.934934943 +0400
@@ -317,11 +317,17 @@
 
 #ifdef Q_OS_FREEBSD
     char *cType;
-    if ( fstype=="vfat" && halOptions.contains("-L=")) {
-        if ( (cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG")) )
+    if ( fstype=="vfat" ) {
+        if ( halOptions.contains("-L=") && (cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG")) )
               options << "-L="+QString(cType);
+        if ( halOptions.contains("large") )
+              options << "large";
+        if ( halOptions.contains("-m=") )
+              options << "-m=644";
+        if ( halOptions.contains("-M=") )
+              options << "-M=755";
     }
-    else if ( (fstype.startsWith(QLatin1String("ntfs")) || fstype=="iso9660" || fstype=="udf") && halOptions.contains("-C=") ) {
+    else if ( (fstype=="ntfs" || fstype=="iso9660" || fstype=="udf") && halOptions.contains("-C=") ) {
         if ((cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG")) )
             options << "-C="+QString(nl_langinfo(CODESET));
     }
@@ -336,6 +342,7 @@
         if (halOptions.contains("flush"))
             options<<"flush";
     }
+#endif
     // pass our locale to the ntfs-3g driver so it can translate local characters
     else if ( halOptions.contains("locale=") ) {
         // have to obtain LC_CTYPE as returned by the `locale` command
@@ -345,7 +352,6 @@
             options << "locale="+QString(cType);
         }
     }
-#endif
 
     msg << "" << fstype << options;
 
