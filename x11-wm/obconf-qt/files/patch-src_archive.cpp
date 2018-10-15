--- src/archive.cpp.orig	2015-02-25 14:12:33 UTC
+++ src/archive.cpp
@@ -1,4 +1,5 @@
 #include <QMessageBox>
+#include <QtGlobal>
 
 #include <glib.h>
 #include <string.h>
@@ -161,6 +162,7 @@ static gchar* install_theme_to(const gch
     GError *e = NULL;
     gchar *name = NULL;
 
+#if defined(Q_OS_LINUX)
     argv = g_new(gchar*, 11);
     argv[0] = g_strdup("tar");
     argv[1] = g_strdup("-x");
@@ -173,6 +175,18 @@ static gchar* install_theme_to(const gch
     argv[8] = g_strdup(to);
     argv[9] = g_strdup("*/openbox-3/");
     argv[10] = NULL;
+#else
+    argv = g_new(gchar*, 9);
+    argv[0] = g_strdup("tar");
+    argv[1] = g_strdup("-x");
+    argv[2] = g_strdup("-v");
+    argv[3] = g_strdup("-z");
+    argv[4] = g_strdup("-f");
+    argv[5] = g_strdup(file);
+    argv[6] = g_strdup("-C");
+    argv[7] = g_strdup(to);
+    argv[8] = NULL;
+#endif
     if (!g_spawn_sync(NULL, argv, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL,
                       &outtxt, &errtxt, &exitcode, &e))
         QMessageBox::critical(NULL, QString(), QObject::tr("Unable to run the \"tar\" command: %1")
