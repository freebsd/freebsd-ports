--- ext/gtk2/rbgtkrecentfilterinfo.c.orig	2011-12-06 02:31:21.000000000 +0000
+++ ext/gtk2/rbgtkrecentfilterinfo.c	2011-12-06 02:32:42.000000000 +0000
@@ -103,7 +103,7 @@
 static VALUE
 rf_set_applications(VALUE self, VALUE applications)
 {
-    /* NOTE: This can’t be right.  What guarantees that the entries in
+    /* NOTE: This can't be right.  What guarantees that the entries in
      * applications will be around?  It should be RVAL2STRV_DUP and use
      * g_strfreev in free above. */
     _SELF(self)->applications = RVAL2STRV(applications);
