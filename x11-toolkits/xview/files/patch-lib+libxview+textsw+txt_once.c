--- lib/libxview/textsw/txt_once.c.orig	2012-02-04 10:11:25.924750298 -0800
+++ lib/libxview/textsw/txt_once.c	2012-02-04 10:26:43.570466001 -0800
@@ -44,7 +44,7 @@
 #ifdef OW_I18N
 #include <xview_private/draw_impl.h>
 #endif
-#if defined SVR4 || __CYGWIN__
+#if defined SVR4 || __CYGWIN__ || defined __FreeBSD__
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -1091,6 +1091,7 @@
     /* Remove from the list. */
     textsw_unlink_view(folio, view);
     /* Destroy all of the view's auxillary objects and any back links */
+    textsw_unlink_view(folio,view);
     ev_destroy(view->e_view);
     free((char *) view);
 }
@@ -1357,7 +1358,11 @@
 	    
 	xv_destroy(view->drop_site);
 	textsw_view_cleanup(view);
+#ifdef __FreeBSD__
+	((Xv_textsw_view *) (view_public))->private_data = NULL;
+#else
 	VIEW_PRIVATE(view_public) = NULL; /* WG Mar '95 */
+#endif
 	break;
 
       default:			/* Conservative in face of new cases. */
