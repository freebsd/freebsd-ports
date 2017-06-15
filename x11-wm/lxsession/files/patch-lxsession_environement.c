--- lxsession/environement.c.orig	2016-12-10 01:54:04 UTC
+++ lxsession/environement.c
@@ -963,7 +963,7 @@ void lxsession_lxsession_env_set_misc (L
 			gchar* _tmp31_ = NULL;
 			gchar* _tmp32_ = NULL;
 			_tmp30_ = qt_plugin;
-			_tmp31_ = g_strconcat (_tmp30_, ":/usr/lib64/kde4/plugins:/usr/lib/kde4/plugins", NULL);
+			_tmp31_ = g_strconcat (_tmp30_, ":%%QT4_LIBDIR%%/plugins:%%QT5_LIBDIR%%/plugins", NULL);
 			_tmp32_ = _tmp31_;
 			g_setenv ("QT_PLUGIN_PATH", _tmp32_, TRUE);
 			_g_free0 (_tmp32_);
