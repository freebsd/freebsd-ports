--- test/power.c.orig	2026-09-29 16:02:14 UTC
+++ test/power.c
@@ -9,7 +9,13 @@ int sd_bus_process(sd_bus *bus, sd_bus_message **messa
 int sd_bus_process(sd_bus *bus, sd_bus_message **message) {
     (void)bus; (void)message; return -ECONNRESET;
 }
+#ifdef HAVE_SD_BUS_CLOSE_UNREF
 sd_bus *sd_bus_close_unref(sd_bus *bus) { (void)bus; closes++; return NULL; }
+#else
+/* power.c emulates sd_bus_close_unref() with these two calls. */
+void sd_bus_close(sd_bus *bus) { (void)bus; closes++; }
+sd_bus *sd_bus_unref(sd_bus *bus) { (void)bus; return NULL; }
+#endif
 void owed_app_on_policy_changed(void) {}
 
 int main(void) {
