--- src/Screen.cc.orig	Sun Nov 17 12:27:50 2002
+++ src/Screen.cc	Sun Nov 24 18:23:28 2002
@@ -284,7 +284,7 @@
 	image_control->setDither(*resource.image_dither);
 	theme = new Theme(getBaseDisplay()->getXDisplay(), getRootWindow(), colormap(), getScreenNumber(), 
 			image_control, fluxbox->getStyleFilename(), getRootCommand().c_str());
-
+	theme->reconfigure(*resource.antialias);
 
 	const char *s =	i18n->getMessage(
 		FBNLS::ScreenSet, FBNLS::ScreenPositionLength,
@@ -447,7 +447,6 @@
 
 	XFree(children);
 	XFlush(getBaseDisplay()->getXDisplay());
-	theme->reconfigure(*resource.antialias);
 }
 
 namespace {
