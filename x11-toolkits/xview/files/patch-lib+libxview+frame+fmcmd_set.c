--- ./lib/libxview/frame/fmcmd_set.c.orig	Tue Jun 29 07:16:07 1993
+++ ./lib/libxview/frame/fmcmd_set.c	Sat Apr  1 18:25:24 2000
@@ -18,6 +18,8 @@ static char     sccsid[] = "@(#)fmcmd_se
 #include <xview/panel.h>
 #include <xview/server.h>
 
+static int update_default_pin_state();
+
 Pkg_private     Xv_opaque
 frame_cmd_set_avlist(frame_public, avlist)
     Frame           frame_public;
