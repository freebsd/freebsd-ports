diff --git a/meson.build b/meson.build
index e3d81daeead3dd0c04fd67df5354d82a832d396e..931681a943bb58da6ac6cf99e5947ac7816d818b 100644
--- meson.build
+++ meson.build
@@ -87,6 +87,12 @@ if cc.has_header_symbol('dirent.h', 'versionsort', prefix : prefix)
 	config_h.set('HAVE_VERSIONSORT', '1')
 endif
 
+if not cc.has_header_symbol('errno.h', 'program_invocation_short_name', prefix : prefix)
+	if cc.has_header_symbol('stdlib.h', 'getprogname')
+		config_h.set('program_invocation_short_name', 'getprogname()')
+	endif
+endif
+
 if cc.has_header('xlocale.h')
 	config_h.set('HAVE_XLOCALE_H', '1')
 endif
