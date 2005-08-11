--- src/wmspec.c.sav	2004-10-24 21:36:15.000000000 +0200
+++ src/wmspec.c	2005-01-26 17:13:54.266216856 +0100
@@ -314,15 +314,15 @@
 void
 wNETWMUpdateDesktop(WScreen *scr)
 {
-    CARD32 *views, sizes[2];
+    long *views, sizes[2];
     int count, i;
 
     if (scr->workspace_count==0)
         return;
 
     count = scr->workspace_count * 2;
-    views = wmalloc(sizeof(CARD32) * count);
-    /*memset(views, 0, sizeof(CARD32) * count);*/
+    views = wmalloc(sizeof(long) * count);
+    /*memset(views, 0, sizeof(long) * count);*/
 
 #ifdef VIRTUAL_DESKTOP
     sizes[0] = scr->workspaces[scr->current_workspace]->width;
@@ -362,7 +362,7 @@
                                0, 1, &count);
     if (prop)
     {
-        int desktop= *(CARD32*)prop;
+        int desktop= *(long*)prop;
         XFree(prop);
         return desktop;
     }
@@ -426,7 +426,7 @@
 static void
 updateShowDesktop(WScreen * scr, Bool show)
 {
-    CARD32 foo;
+    long foo;
 
     foo = (show == True);
     XChangeProperty(dpy, scr->root_win, net_showing_desktop, XA_CARDINAL, 32,
@@ -599,7 +599,7 @@
 void
 wNETWMUpdateWorkarea(WScreen *scr, WArea usableArea)
 {
-    CARD32 *area;
+    long *area;
     int count, i;
 
     /* XXX: not Xinerama compatible,
@@ -609,7 +609,7 @@
         return;
 
     count = scr->workspace_count * 4;
-    area = wmalloc(sizeof(CARD32) * count);
+    area = wmalloc(sizeof(long) * count);
     for (i=0; i<scr->workspace_count; i++) {
         area[4*i + 0] = usableArea.x1;
         area[4*i + 1] = usableArea.y1;
@@ -732,7 +732,7 @@
 static void
 updateWorkspaceCount(WScreen *scr) /* changeable */
 {
-    CARD32 count;
+    long count;
 
     count = scr->workspace_count;
 
@@ -744,7 +744,7 @@
 static void
 updateCurrentWorkspace(WScreen *scr) /* changeable */
 {
-    CARD32 count;
+    long count;
 
     count = scr->current_workspace;
 
@@ -791,7 +791,7 @@
 static void
 updateWorkspaceHint(WWindow *wwin, Bool fake, Bool del)
 {
-    CARD32 l;
+    long l;
 
     if (del) {
         XDeleteProperty(dpy, wwin->client_win, net_wm_desktop);
