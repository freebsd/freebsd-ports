--- src/Waimea.cc.orig	Thu Nov  4 06:22:46 2004
+++ src/Waimea.cc	Thu Mar  3 19:21:22 2005
@@ -1151,7 +1151,7 @@
 #ifdef    THREAD
 void *render_thread_func(void *) {
     sigset_t sigset;
-    cairo_state_t *cr = cairo_create();
+    cairo_t *cr = cairo_create();
 
     /* XXX: cairo need a call to this function for text support to be
        initialized, will probably dissapear soon. */
