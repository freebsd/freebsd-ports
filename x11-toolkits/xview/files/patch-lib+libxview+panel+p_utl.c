--- lib/libxview/panel/p_utl.c.orig	Sun Oct  5 11:58:54 2003
+++ lib/libxview/panel/p_utl.c	Sun Oct  5 12:08:09 2003
@@ -168,11 +168,6 @@
         if (image_string_wc(dest))
             xv_free(image_string_wc(dest));
     }
-#else
-    {
-        if (image_string(dest))
-            xv_free(image_string(dest));
-    }
 #endif
 
     size.x = size.y = 0;
@@ -195,6 +190,8 @@
 	    value_str = "";
 	if (!(str = (char *) panel_strsave((u_char *) value_str)))
 	    return (size);
+        if (image_string(dest))	/* lmfken Oct-93 */
+            xv_free(image_string(dest));
 	image_set_string(dest, str);
 #endif
 	panel_image_set_font(dest, font);
