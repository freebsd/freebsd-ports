--- gnome-panel/egg-recent-model.c.orig	Wed Dec 21 16:58:46 2005
+++ gnome-panel/egg-recent-model.c	Wed Dec 21 16:59:03 2005
@@ -942,7 +942,7 @@
 static gboolean
 egg_recent_model_lock_file (FILE *file)
 {
-#ifdef F_TLOCK
+#ifdef HAVE_LOCKF
 	int fd;
 	gint	try = 5;
 
@@ -980,7 +980,7 @@
 static gboolean
 egg_recent_model_unlock_file (FILE *file)
 {
-#ifdef F_TLOCK
+#ifdef HAVE_LOCKF
 	int fd;
 
 	rewind (file);
