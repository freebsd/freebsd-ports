--- menu-cache-daemon/menu-cached.c.orig	2012-11-14 09:07:36.000000000 +0100
+++ menu-cache-daemon/menu-cached.c	2013-07-01 00:02:26.000000000 +0200
@@ -121,7 +121,7 @@
 static gboolean read_all_used_files( FILE* f, int* n_files, char*** used_files )
 {
     char line[ 4096 ];
-    int i, n;
+    int i, n, x;
     char** files;
     int ver_maj, ver_min;
 
@@ -141,20 +141,31 @@
     if( ! fgets( line, G_N_ELEMENTS(line), f ) )
         return FALSE;
 
-    *n_files = n = atoi( line );
+    n = atoi( line );
     files = g_new0( char*, n + 1 );
 
-    for( i = 0; i < n; ++i )
+    for( i = 0, x = 0; i < n; ++i )
     {
         int len;
+        GFile *gfile;
         if( ! fgets( line, G_N_ELEMENTS(line), f ) )
             return FALSE;
 
         len = strlen( line );
         if( len <= 1 )
             return FALSE;
-        files[ i ] = g_strndup( line, len - 1 ); /* don't include \n */
+        files[ x ] = g_strndup( line, len - 1 ); /* don't include \n */
+        gfile = g_file_new_for_path(files[x]+1);
+        if (g_file_query_exists(gfile, NULL))
+            x++;
+        else
+        {
+            DEBUG("ignoring not existant file from menu-cache-gen: %s", files[x]);
+            g_free(files[x]);
+        }
+        g_object_unref(gfile);
     }
+    *n_files = x;
     *used_files = files;
     return TRUE;
 }
