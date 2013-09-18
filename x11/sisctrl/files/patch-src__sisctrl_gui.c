--- src/sisctrl_gui.c.orig	2013-09-05 22:15:13.000000000 +0900
+++ src/sisctrl_gui.c	2013-09-05 22:16:07.000000000 +0900
@@ -5885,8 +5885,8 @@
 {
    /*fprintf(stderr, "conf\n");*/
    if(gl.noxvdemo) return TRUE;
-   if(gui.notebook_page != SIS_PAGE_VIDEO) return;
-   if(!gui.xvwin) return;
+   if(gui.notebook_page != SIS_PAGE_VIDEO) return TRUE;
+   if(!gui.xvwin) return TRUE;
    if(!gui.xvinit) return TRUE;
    resizexvwindow();
    showxvimage();
