--- build/Wx/build/Utils.pm.orig	2014-03-08 13:01:15 UTC
+++ build/Wx/build/Utils.pm
@@ -107,7 +107,7 @@ sub scan_xs($$$) {
     m/^\s*INCLUDE:\s+(.*)$/ and $file = $1 and $arr = \@xsinclude;
     m/^\s*INCLUDE_COMMAND:\s+.*\s(\S+\.(?:xsp?|h))\s*/ and $file = $1 and
       $arr = \@xsinclude;
-    m/^\s*\%include{([^}]+)}\s*;\s*$/ and $file = $1 and $arr = \@xsinclude;
+    m/^\s*\%include\{([^}]+)\}\s*;\s*$/ and $file = $1 and $arr = \@xsinclude;
 
     if( defined $file ) {
       $file = catfile( split '/', $file );
