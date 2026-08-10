--- src/vt.c.orig	2026-08-06 19:53:11 UTC
+++ src/vt.c
@@ -46,7 +46,9 @@ vt_can_multi_seat (void)
 gboolean
 vt_can_multi_seat (void)
 {
-#if defined(__linux__)
+#if defined(__FreeBSD__)
+    return TRUE;
+#elif defined(__linux__)
     /* Quick check to see if we can multi seat.  This is intentionally the
        same check logind does, just without actually reading from the files.
        Existence will prove whether we have CONFIG_VT built into the kernel. */
