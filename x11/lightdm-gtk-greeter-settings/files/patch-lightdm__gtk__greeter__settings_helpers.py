--- lightdm_gtk_greeter_settings/helpers.py.orig	2020-03-08 02:41:40 UTC
+++ lightdm_gtk_greeter_settings/helpers.py
@@ -184,8 +184,8 @@ def check_path_accessibility(path, file=True, executab
     try:
         uid, gids = check_path_accessibility.id_cached_data
     except AttributeError:
-        files = glob.glob('/etc/lightdm/lightdm.d/*.conf')
-        files += ['/etc/lightdm/lightdm.conf']
+        files = glob.glob('%%LOCALBASE%%/etc/lightdm/lightdm.d/*.conf')
+        files += ['%%LOCALBASE%%/etc/lightdm/lightdm.conf']
         config = configparser.RawConfigParser(strict=False)
         config.read(files)
         username = config.get('LightDM', 'greeter-user', fallback='lightdm')
