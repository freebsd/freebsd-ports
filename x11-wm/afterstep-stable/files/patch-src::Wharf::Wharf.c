--- src/Wharf/Wharf.c.orig	Tue Sep 28 05:39:05 2004
+++ src/Wharf/Wharf.c	Wed Sep 29 14:03:36 2004
@@ -2357,8 +2357,9 @@
             unmap_wharf_folder( aswf );
         }else if( changes != 0 )
         {
+            int i;
 LOCAL_DEBUG_OUT("animation_steps = %d", aswf->animation_steps );
-            int i = aswf->buttons_num ;
+            i = aswf->buttons_num ;
 
 			if( !get_flags( aswf->flags, ASW_Withdrawn ) )
 			{	
