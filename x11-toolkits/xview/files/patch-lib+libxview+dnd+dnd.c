--- ./lib/libxview/dnd/dnd.c.orig	Tue Jun 29 07:15:57 1993
+++ ./lib/libxview/dnd/dnd.c	Sat Apr  1 18:25:23 2000
@@ -38,6 +38,10 @@ static void UpdateGrabCursor();
 extern int  DndContactDSDM();
 extern int  DndFindSite();
 extern XID  DndGetCursor();
+static int SendTrigger();
+static int SendOldDndEvent();
+static int WaitForAck();
+static int IsV2App();
 
 Xv_public int
 dnd_send_drop(dnd_public)
