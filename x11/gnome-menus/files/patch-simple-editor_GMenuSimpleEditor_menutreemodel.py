--- simple-editor/GMenuSimpleEditor/menutreemodel.py.orig	Mon Apr 11 05:36:04 2005
+++ simple-editor/GMenuSimpleEditor/menutreemodel.py	Tue Sep  6 11:04:46 2005
@@ -29,7 +29,7 @@
     if os.environ.has_key ("XDG_CONFIG_DIRS"):
         conf_dirs = os.environ["XDG_CONFIG_DIRS"]
     if not conf_dirs:
-        conf_dirs = "/etc/xdg"
+	conf_dirs = "%%LOCALBASE%%/etc/xdg"
 
     for conf_dir in conf_dirs.split (":"):
         menu_file_path = os.path.join (conf_dir, "menus", menu_file)
@@ -51,7 +51,7 @@
     if os.environ.has_key ("XDG_DATA_DIRS"):
         data_dirs = os.environ["XDG_DATA_DIRS"]
     if not data_dirs:
-        data_dirs = "/usr/local/share/:/usr/share/"
+	data_dirs = "%%LOCALBASE%%/share/"
 
     for data_dir in data_dirs.split (":"):
         retval = load_icon_from_path (os.path.join (data_dir, "pixmaps", icon_value))
