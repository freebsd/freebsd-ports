diff --git a/meson.build b/meson.build
index 9ff17117a9f6c79bb50362d6db6507ba56c20136..e3d81daeead3dd0c04fd67df5354d82a832d396e 100644
--- meson.build
+++ meson.build
@@ -87,6 +87,10 @@ if cc.has_header_symbol('dirent.h', 'versionsort', prefix : prefix)
 	config_h.set('HAVE_VERSIONSORT', '1')
 endif
 
+if cc.has_header('xlocale.h')
+	config_h.set('HAVE_XLOCALE_H', '1')
+endif
+
 # Dependencies
 pkgconfig = import('pkgconfig')
 dep_udev = dependency('libudev')
diff --git a/src/libinput-util.h b/src/libinput-util.h
index c68b888ad7385d159a1bc35c3b2bf7d324cde44c..85166ca568dd1813f78c98798dbe090cd7486236 100644
--- src/libinput-util.h
+++ src/libinput-util.h
@@ -31,11 +31,15 @@
 #include <errno.h>
 #include <limits.h>
 #include <locale.h>
+#ifdef HAVE_XLOCALE_H
+#include <xlocale.h>
+#endif
 #include <math.h>
 #include <stdarg.h>
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
