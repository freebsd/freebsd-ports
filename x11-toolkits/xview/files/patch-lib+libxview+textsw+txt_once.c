--- lib/libxview/textsw/txt_once.c.orig	Thu Oct  5 19:18:11 2006
+++ lib/libxview/textsw/txt_once.c	Thu Oct  5 19:51:36 2006
@@ -44,7 +44,9 @@
 #ifdef OW_I18N
 #include <xview_private/draw_impl.h>
 #endif
-#ifdef SVR4
+
+#include <sys/param.h>
+#if (defined(BSD4_4) || defined(SVR4))
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -1084,6 +1086,7 @@
 	}
     }
     /* Destroy all of the view's auxillary objects and any back links */
+    textsw_unlink_view(folio,view);
     ev_destroy(view->e_view);
     free((char *) view);
 }
@@ -1350,6 +1353,8 @@
 	    
 	xv_destroy(view->drop_site);
 	textsw_view_cleanup(view);
+
+	((Xv_textsw_view *) (view_public))->private_data = NULL;
 	break;
 
       default:			/* Conservative in face of new cases. */
