--- unix/pkgIndex.tcl	Mon Sep 11 16:27:28 2000
+++ unix/pkgIndex.tcl.new	Sun Mar 14 13:29:27 2004
@@ -5,4 +5,4 @@
 # broken OSes like SunOS4.  If you have a problem with this, tough!
 
 package ifneeded Shape 0.4 "package require Tk 8\n\
-	[list tclPkgSetup $dir Shape 0.4 {{libshape04.so.1.0 load shape}}]"
+	[list tclPkgSetup $dir Shape 0.4 {{libshape04.so.1 load shape}}]"
