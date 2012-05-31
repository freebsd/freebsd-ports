--- ./libmenu-cache/menu-cache.c.orig	2012-03-18 14:12:13.000000000 +1030
+++ ./libmenu-cache/menu-cache.c	2012-03-18 14:13:02.000000000 +1030
@@ -226,7 +226,7 @@
 
     /* file name */
     if( G_UNLIKELY( ! fgets( line, G_N_ELEMENTS(line) - 1, f ) ))
-        return;
+        return NULL;
     len = strlen( line );
     if( G_LIKELY(len > 1) )
         item->file_name = g_strndup( line, len - 1 );
@@ -240,7 +240,7 @@
 
     /* desktop file dir */
     if( G_UNLIKELY( ! fgets( line, G_N_ELEMENTS(line) - 1, f ) ))
-        return;
+        return NULL;
     idx = atoi( line );
     if( G_LIKELY( idx >=0 && idx < cache->n_all_used_files ) )
         item->file_dir = cache->all_used_files[ idx ] + 1;
