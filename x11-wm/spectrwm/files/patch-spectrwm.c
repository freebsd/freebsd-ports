--- spectrwm.c.orig	2013-04-29 23:55:24.573913339 +0200
+++ spectrwm.c	2013-04-29 23:55:44.031914326 +0200
@@ -6316,7 +6316,7 @@
 void
 setup_spawn(void)
 {
-	setconfspawn("lock",		"xlock",		0);
+	setconfspawn("lock",		"xlock",		SWM_SPAWN_OPTIONAL);
 
 	setconfspawn("term",		"xterm",		0);
 	setconfspawn("spawn_term",	"xterm",		0);
