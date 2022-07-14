--- src/kgx-pages.c.orig	2022-07-14 22:39:12 UTC
+++ src/kgx-pages.c
@@ -835,7 +835,9 @@ kgx_pages_get_children (KgxPages *self)
   GPtrArray *children;
   guint n;
 
+#ifndef __FreeBSD__
   g_return_val_if_fail (KGX_IS_PAGES (self), KGX_NONE);
+#endif
 
   priv = kgx_pages_get_instance_private (self);
 
