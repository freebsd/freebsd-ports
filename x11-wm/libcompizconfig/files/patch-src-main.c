--- src/main.c.orig	2008-04-03 12:04:50.000000000 -0400
+++ src/main.c	2008-05-29 17:02:49.000000000 -0400
@@ -549,7 +549,8 @@
 	asprintf (&dlname, "%s/.compizconfig/backends/lib%s.so", 
 		  home, backend);
 	dlerror ();
-	dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_LOCAL);
+	dlhand = dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
+	dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
 	err = dlerror ();
     }
 
@@ -560,7 +561,8 @@
         }
 	asprintf (&dlname, "%s/compizconfig/backends/lib%s.so", 
 		  LIBDIR, backend);
-	dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_LOCAL);
+	dlhand = dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
+	dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
 	err = dlerror ();
     }
 
