--- src/screen.c.orig	Sat May  6 19:21:53 2006
+++ src/screen.c	Sat May  6 19:22:13 2006
@@ -187,6 +187,20 @@
 {
   MetaDisplay *display;
 
+  {
+    GList *tmp;
+
+    tmp = screen->workspaces;
+    while (tmp != NULL)
+      {
+        MetaWorkspace *space = tmp->data;
+
+        meta_workspace_invalidate_work_area (space);
+        
+        tmp = tmp->next;
+      }
+  }
+
   display = screen->display;
   
   if (screen->xinerama_infos)
@@ -348,20 +362,6 @@
 
   g_assert (screen->n_xinerama_infos > 0);
   g_assert (screen->xinerama_infos != NULL);
-
-  {
-    GList *tmp;
-
-    tmp = screen->workspaces;
-    while (tmp != NULL)
-      {
-        MetaWorkspace *space = tmp->data;
-
-        meta_workspace_invalidate_work_area (space);
-        
-        tmp = tmp->next;
-      }
-  }
 }
 
 MetaScreen*
