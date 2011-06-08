--- lib/libxview/server/server.c.orig	1994-06-26 11:53:40.000000000 -0700
+++ lib/libxview/server/server.c	2011-06-08 10:21:36.653037943 -0700
@@ -25,6 +25,7 @@
 #include <xview/win_notify.h>
 #include <xview/defaults.h>
 #include <X11/Xlib.h>
+#include <X11/Xlibint.h>
 #include <xview_private/portable.h>
 #include <xview_private/svr_atom.h>
 #include <xview_private/svr_impl.h>
@@ -65,6 +66,7 @@
 static unsigned int 	 string_to_modmask();
 static Server_atom_type  save_atom();
 static void 		 server_yield_modifiers();
+static int		 xv_set_scheduler();
 
 Xv_private char		*xv_strtok();
 
@@ -440,7 +442,7 @@
   	/* lumpi@dobag.in-berlin.de */
     if (XrmGetDatabase((Display *)server->xdisplay)) {
 	server->db = XrmGetStringDatabase(
-				(XrmGetDatabase((Display *)server->xdisplay)));
+				(char *) (XrmGetDatabase((Display *)server->xdisplay)));
 #else
     if (((Display *)server->xdisplay)->xdefaults) {
 	server->db = XrmGetStringDatabase(
@@ -741,10 +743,8 @@
      */
 
     /* Used by atom mgr */
-    server->atom_mgr[ATOM] = (XID) XAllocID((Display *)server->xdisplay);
-    server->atom_mgr[NAME] = (XID) XAllocID((Display *)server->xdisplay);
-    server->atom_mgr[TYPE] = (XID) XAllocID((Display *)server->xdisplay);
-    server->atom_mgr[DATA] = (XID) XAllocID((Display *)server->xdisplay);
+    /* XXX Fixed by Ubuntu bug 89166 */
+    XAllocIDs((Display *)server->xdisplay, server->atom_mgr, 4);
 
     /* Key for XV_KEY_DATA.  Used in local dnd ops. */
     server->dnd_ack_key = xv_unique_key();
