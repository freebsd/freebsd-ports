--- otk_lib.h.orig
+++ otk_lib.h
@@ -283,4 +283,7 @@
 
 OtkFont *Otk_Read_SVG_Font( char *filename );  /* FONTS insertion */
 
+extern struct OtkObjectInstance *OtkRootObject, *OtkOuterWindow,
+		*Otk_keyboard_focus, *Otk_OpenMenu;
+
 #endif
