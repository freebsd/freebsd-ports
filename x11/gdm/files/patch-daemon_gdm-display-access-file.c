--- daemon/gdm-display-access-file.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-display-access-file.c
@@ -337,9 +337,18 @@ _create_xauth_file_for_user (const char  *username,
         g_debug ("GdmDisplayAccessFile: creating %s", auth_filename);
         /* mode 00600 */
         errno = 0;
-        fd = g_open (auth_filename,
-                     O_RDWR | O_CREAT | O_EXCL | O_BINARY,
-                     S_IRUSR | S_IWUSR);
+#if defined(__OpenBSD__)
+        if (uid == 676) {
+                fd = g_open (auth_filename,
+                             O_RDWR | O_CREAT | O_EXCL | O_BINARY,
+                             S_IRUSR | S_IWUSR | S_IRGRP);
+        } else
+#endif
+        {
+                fd = g_open (auth_filename,
+                             O_RDWR | O_CREAT | O_EXCL | O_BINARY,
+                             S_IRUSR | S_IWUSR);
+        }
 
         if (fd < 0) {
                 g_set_error (error,
@@ -441,9 +450,9 @@ _get_auth_info_for_display (GdmDisplayAccessFile *file
                  *
                  * https://bugs.freedesktop.org/show_bug.cgi?id=43425
                  */
-                char localhost[HOST_NAME_MAX + 1] = "";
+                char localhost[256] = "";
                 *family = FamilyLocal;
-                if (gethostname (localhost, HOST_NAME_MAX) == 0) {
+                if (gethostname (localhost, 255) == 0) {
                         *address = g_strdup (localhost);
                 } else {
                         *address = g_strdup ("localhost");
