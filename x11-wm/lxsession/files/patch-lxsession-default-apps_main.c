--- lxsession-default-apps/main.c.orig	2016-12-10 10:31:48 UTC
+++ lxsession-default-apps/main.c
@@ -1842,7 +1842,7 @@ LDefaultAppsMainWindows* ldefault_apps_m
 			gchar* _tmp14_ = NULL;
 			GtkBuilder* _tmp15_ = NULL;
 			const gchar* _tmp16_ = NULL;
-			_tmp14_ = g_build_filename ("/usr", "share", "lxsession", "ui", "lxsession-default-apps.ui", NULL);
+			_tmp14_ = g_build_filename ("%%PREFIX%%", "share", "lxsession", "ui", "lxsession-default-apps.ui", NULL);
 			_g_free0 (builder_file_path);
 			builder_file_path = _tmp14_;
 			_tmp15_ = builder;
