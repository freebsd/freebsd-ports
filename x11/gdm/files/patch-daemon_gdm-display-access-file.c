--- daemon/gdm-display-access-file.c.orig	2023-09-14 15:27:04 UTC
+++ daemon/gdm-display-access-file.c
@@ -337,9 +337,11 @@ _create_xauth_file_for_user (const char  *username,
         g_debug ("GdmDisplayAccessFile: creating %s", auth_filename);
         /* mode 00600 */
         errno = 0;
-        fd = g_open (auth_filename,
-                     O_RDWR | O_CREAT | O_EXCL | O_BINARY,
-                     S_IRUSR | S_IWUSR);
+        {
+                fd = g_open (auth_filename,
+                             O_RDWR | O_CREAT | O_EXCL | O_BINARY,
+                             S_IRUSR | S_IWUSR);
+        }
 
         if (fd < 0) {
                 g_set_error (error,
@@ -429,9 +431,9 @@ _get_auth_info_for_display (GdmDisplayAccessFile *file
                  *
                  * https://bugs.freedesktop.org/show_bug.cgi?id=43425
                  */
-                char localhost[HOST_NAME_MAX + 1] = "";
+                char localhost[_POSIX_HOST_NAME_MAX + 1] = "";
                 *family = FamilyLocal;
-                if (gethostname (localhost, HOST_NAME_MAX) == 0) {
+                if (gethostname (localhost, _POSIX_HOST_NAME_MAX) == 0) {
                         *address = g_strdup (localhost);
                 } else {
                         *address = g_strdup ("localhost");
