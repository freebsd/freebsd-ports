--- Basewindow.cc.orig	Sun Aug 15 07:43:55 1999
+++ Basewindow.cc	Sat Aug  4 20:52:40 2001
@@ -23,6 +23,13 @@
 
 Basewindow::Basewindow(int argc,char **argv)
 {
+	dpy = NULL;
+	v = NULL;
+	image_control = NULL;
+	nobb_filename = NULL;
+	bbconfig_filename = NULL;
+	spooldir = NULL;
+
 	display_name=NULL;
 	config_filename=NULL;
 	position=NULL;
