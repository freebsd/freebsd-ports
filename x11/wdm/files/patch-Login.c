--- src/Login.c	Tue Feb 29 06:17:01 2000
+++ src/Login.c.new	Wed Apr  3 22:36:34 2002
@@ -24,6 +24,9 @@
 #include <X11/xpm.h>
 #include <X11/keysym.h>
 #include <X11/cursorfont.h>
+#ifdef HAVE_XINERAMA
+#include <X11/extensions/Xinerama.h>
+#endif
 #ifdef HAVE_X11_WINGS_H
 #include <X11/WINGs.h>
 #else
@@ -1195,6 +1198,10 @@
 int main(int argc, char **argv)
 {
     WMScreen   *scr;
+    int xine_count; int c;
+#ifdef HAVE_XINERAMA
+    XineramaScreenInfo *xine;
+#endif
 
     ProgName = argv[0];
 
@@ -1210,8 +1217,28 @@
     }
 
     screen_number = DefaultScreen(dpy);
-    screen_width = DisplayWidth(dpy,screen_number);
-    screen_heigth = DisplayHeight(dpy,screen_number);
+#ifdef HAVE_XINERAMA
+    if (XineramaIsActive(dpy)) {
+	xine = XineramaQueryScreens(dpy, &xine_count);
+		
+	if (xine != NULL) {
+		for (c = 0;c < xine_count;c++) {
+			if (xine[c].screen_number == 0) {
+    				screen_width = xine[c].width;
+				screen_heigth = xine[c].height;
+			}
+		}
+	} else {
+		screen_width = DisplayWidth(dpy, screen_number);
+		screen_heigth = DisplayHeight(dpy, screen_number);
+	}
+    } else {
+#endif
+	screen_width = DisplayWidth(dpy,screen_number);
+	screen_heigth = DisplayHeight(dpy,screen_number);
+#ifdef HAVE_XINERAMA
+    }
+#endif
     panel_X = (screen_width  - panel_width)/2;
     panel_Y = (screen_heigth - panel_heigth)/2;
 
