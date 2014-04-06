--- spectrwm.c.orig	2014-04-06 09:43:33.000000000 +0200
+++ spectrwm.c	2014-04-06 09:43:33.000000000 +0200
@@ -7008,7 +7008,7 @@
 void
 setup_spawn(void)
 {
-	setconfspawn("lock",		"xlock",		0);
+	setconfspawn("lock",		"xlock",		SWM_SPAWN_OPTIONAL);
 
 	setconfspawn("term",		"xterm",		0);
 	setconfspawn("spawn_term",	"xterm",		0);
