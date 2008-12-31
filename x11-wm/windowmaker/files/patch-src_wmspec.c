--- src/wmspec.c.sav	2005-05-15 09:41:09.000000000 -0700
+++ src/wmspec.c	2008-12-31 01:47:07.000000000 -0800
@@ -322,15 +322,15 @@
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
@@ -370,7 +370,7 @@
                                0, 1, &count);
     if (prop)
     {
-        int desktop= *(CARD32*)prop;
+        int desktop= *(long*)prop;
         XFree(prop);
         return desktop;
     }
@@ -389,12 +389,12 @@
  *
  * The logic can also be changed to accept bigger images and scale them down.
  */
-static CARD32*
-findBestIcon(CARD32 *data, unsigned long items)
+static unsigned long*
+findBestIcon(unsigned long *data, unsigned long items)
 {
     int size, wanted, d, distance;
     unsigned long i;
-    CARD32 *icon;
+    unsigned long *icon;
 
     /* better use only 75% of icon_size. For 64x64 this means 48x48
      * This leaves room around the icon for the miniwindow title and
@@ -418,7 +418,7 @@
 
 
 static RImage*
-makeRImageFromARGBData(CARD32 *data)
+makeRImageFromARGBData(unsigned long *data)
 {
     int size, width, height, i;
     RImage *image;
@@ -449,7 +449,7 @@
 static void
 updateIconImage(WScreen *scr, WWindow *wwin)
 {
-    CARD32 *property, *data;
+    unsigned long *property, *data;
     unsigned long items, rest;
     Atom type;
     int format;
@@ -487,7 +487,7 @@
 static void
 updateShowDesktop(WScreen * scr, Bool show)
 {
-    CARD32 foo;
+    long foo;
 
     foo = (show == True);
     XChangeProperty(dpy, scr->root_win, net_showing_desktop, XA_CARDINAL, 32,
@@ -660,7 +660,7 @@
 void
 wNETWMUpdateWorkarea(WScreen *scr, WArea usableArea)
 {
-    CARD32 *area;
+    long *area;
     int count, i;
 
     /* XXX: not Xinerama compatible,
@@ -670,7 +670,7 @@
         return;
 
     count = scr->workspace_count * 4;
-    area = wmalloc(sizeof(CARD32) * count);
+    area = wmalloc(sizeof(long) * count);
     for (i=0; i<scr->workspace_count; i++) {
         area[4*i + 0] = usableArea.x1;
         area[4*i + 1] = usableArea.y1;
@@ -793,7 +793,7 @@
 static void
 updateWorkspaceCount(WScreen *scr) /* changeable */
 {
-    CARD32 count;
+    long count;
 
     count = scr->workspace_count;
 
@@ -805,7 +805,7 @@
 static void
 updateCurrentWorkspace(WScreen *scr) /* changeable */
 {
-    CARD32 count;
+    long count;
 
     count = scr->current_workspace;
 
@@ -852,7 +852,7 @@
 static void
 updateWorkspaceHint(WWindow *wwin, Bool fake, Bool del)
 {
-    CARD32 l;
+    long l;
 
     if (del) {
         XDeleteProperty(dpy, wwin->client_win, net_wm_desktop);
