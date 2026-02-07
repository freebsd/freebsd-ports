--- lib/listdir.c.orig	2014-06-28 20:34:29 UTC
+++ lib/listdir.c
@@ -970,7 +970,11 @@ tc_scandir( const char      * dirname,
 #if defined __VMS && __VMS_VER < 70000000 || defined opennt || defined __CYGWIN__
         total = dname_is_1 ? strlen( dentry->d_name ) : sizeof *dentry;
 #else
+#  ifdef __DragonFly__
+        total = dname_is_1 ? _DIRENT_RECLEN(dentry->d_namlen) : sizeof *dentry;
+#  else
         total = dname_is_1 ? dentry->d_reclen : sizeof *dentry;
+#  endif
 #endif
         memcpy( head[ n ] = fl_malloc( total ), dentry, total );
     }
