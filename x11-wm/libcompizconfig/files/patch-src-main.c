--- src/main.c.orig	2007-08-12 15:59:57.000000000 -0400
+++ src/main.c	2007-09-05 11:38:34.000000000 -0400
@@ -550,7 +550,8 @@
 	asprintf (&dlname, "%s/.compizconfig/backends/lib%s.so", 
 		  home, backend);
 	dlerror ();
-	dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_GLOBAL);
+	dlhand = dlopen (dlname, RTLD_NOW | RTLD_GLOBAL);
+	dlopen (dlname, RTLD_NOW | RTLD_GLOBAL);
 	err = dlerror ();
     }
 
@@ -559,7 +560,8 @@
 	free (dlname);
 	asprintf (&dlname, "%s/compizconfig/backends/lib%s.so", 
 		  LIBDIR, backend);
-	dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_GLOBAL);
+	dlhand = dlopen (dlname, RTLD_NOW | RTLD_GLOBAL);
+	dlopen (dlname, RTLD_NOW | RTLD_GLOBAL);
 	err = dlerror ();
     }
 
