--- daemon/gdm.c.orig	Mon Apr  5 03:11:28 2004
+++ daemon/gdm.c	Tue May 11 00:04:26 2004
@@ -3822,7 +3822,7 @@
 			return;
 		}
 
-#ifdef __linux__
+#if defined  (__linux__) || defined (__FreeBSD__)
 		gdm_connection_printf (conn, "OK %d\n", gdm_get_cur_vt ());
 #else
 		gdm_connection_write (conn, "ERROR 8 Virtual terminals not supported\n");
@@ -3849,7 +3849,7 @@
 			return;
 		}
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 		gdm_change_vt (vt);
 		for (li = displays; li != NULL; li = li->next) {
 			GdmDisplay *disp = li->data;
