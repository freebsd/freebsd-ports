--- battstat/battstat-upower.c.orig	2014-04-06 21:28:44.142056837 +0000
+++ battstat/battstat-upower.c	2014-04-06 21:29:46.913052233 +0000
@@ -86,7 +86,11 @@
   GCancellable *cancellable = g_cancellable_new();
   GError *gerror;
 
+#ifdef HAVE_OLD_UPOWER
   if (! up_client_enumerate_devices_sync( upc, cancellable, &gerror ) ) {
+#else
+  if (FALSE){
+#endif
     sprintf(error_str, "Unable to enumerate upower devices: %s\n", gerror->message);
     goto error_shutdownclient;
   }
