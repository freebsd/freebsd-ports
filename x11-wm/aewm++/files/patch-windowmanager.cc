--- windowmanager.cc.orig	Thu May 15 10:44:12 2003
+++ windowmanager.cc	Thu Aug  5 20:07:05 2004
@@ -623,9 +623,10 @@
 	}
 	if (ks >= XK_1 && ks <= XK_1+(unsigned)max_desktops && ks - XK_1 <= (unsigned)9)  /* no two digit keys */
  	{
-                if( (unsigned)current_desktop != ks - XK_1 )
+                unsigned my_current_desktop = (unsigned)current_desktop;
+                if( my_current_desktop != ks - XK_1 )
 		{
-			(unsigned)current_desktop = ks - XK_1;
+			my_current_desktop = ks - XK_1;
 			goToDesktop(current_desktop);
 		}
 	}
