--- simple-editor/GMenuSimpleEditor/menutreemodel.py.orig	2011-08-16 14:04:56.000000000 +0200
+++ simple-editor/GMenuSimpleEditor/menutreemodel.py	2011-09-17 13:01:18.000000000 +0200
@@ -29,7 +29,7 @@ def lookup_system_menu_file (menu_file):
     if os.environ.has_key ("XDG_CONFIG_DIRS"):
         conf_dirs = os.environ["XDG_CONFIG_DIRS"]
     if not conf_dirs:
-        conf_dirs = "/etc/xdg"
+	conf_dirs = "%%LOCALBASE%%/etc/xdg"
 
     for conf_dir in conf_dirs.split (":"):
         menu_file_path = os.path.join (conf_dir, "menus", menu_file)
