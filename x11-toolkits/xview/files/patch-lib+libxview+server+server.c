--- lib/libxview/server/server.c.orig	2012-02-04 10:06:21.849338608 -0800
+++ lib/libxview/server/server.c	2012-02-04 10:10:13.953502758 -0800
@@ -70,6 +70,7 @@
 static unsigned int 	 string_to_modmask();
 static Server_atom_type  save_atom();
 static void 		 server_yield_modifiers();
+static int		 xv_set_scheduler();
 
 Xv_private char		*xv_strtok();
 
@@ -451,14 +452,14 @@
     /* See if defaults have been loaded on server */
 #ifdef X11R6
   	/* lumpi@dobag.in-berlin.de */
-#if 1
+#ifndef __FreeBSD__
     /* martin-2.buck@student.uni-ulm.de */
     if ((xrmstr = XResourceManagerString((Display *)server->xdisplay))) {
 	server->db = XrmGetStringDatabase(xrmstr);
 #else
     if (XrmGetDatabase((Display *)server->xdisplay)) {
 	server->db = XrmGetStringDatabase(
-				(XrmGetDatabase((Display *)server->xdisplay)));
+				(char *) (XrmGetDatabase((Display *)server->xdisplay)));
 #endif
 #else
     if (((Display *)server->xdisplay)->xdefaults) {
@@ -778,10 +779,8 @@
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
