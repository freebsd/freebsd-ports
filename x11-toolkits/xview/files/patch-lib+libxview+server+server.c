--- ./lib/libxview/server/server.c.orig	Sun Jun 26 20:53:40 1994
+++ ./lib/libxview/server/server.c	Sat Apr  1 18:25:28 2000
@@ -65,6 +65,7 @@ static Notify_value 	 scheduler();
 static unsigned int 	 string_to_modmask();
 static Server_atom_type  save_atom();
 static void 		 server_yield_modifiers();
+static int		 xv_set_scheduler();
 
 Xv_private char		*xv_strtok();
 
@@ -440,7 +441,7 @@ server_init(parent, server_public, avlis
   	/* lumpi@dobag.in-berlin.de */
     if (XrmGetDatabase((Display *)server->xdisplay)) {
 	server->db = XrmGetStringDatabase(
-				(XrmGetDatabase((Display *)server->xdisplay)));
+				(char *) (XrmGetDatabase((Display *)server->xdisplay)));
 #else
     if (((Display *)server->xdisplay)->xdefaults) {
 	server->db = XrmGetStringDatabase(
