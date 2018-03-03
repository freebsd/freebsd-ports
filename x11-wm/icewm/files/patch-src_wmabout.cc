--- src/wmabout.cc.orig	2018-02-25 21:00:14.796410000 -0800
+++ src/wmabout.cc	2018-02-25 21:00:22.254233000 -0800
@@ -23,7 +23,7 @@
 AboutDlg *aboutDlg = 0;
 
 AboutDlg::AboutDlg(): YDialog() {
-    char const *version("IceWM "VERSION" ("HOSTOS"/"HOSTCPU")");
+    char const *version("IceWM " VERSION" (" HOSTOS"/" HOSTCPU")");
     ustring copyright =
         ustring("Copyright ")
         .append(_("(C)"))
