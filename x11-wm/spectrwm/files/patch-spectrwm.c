--- spectrwm.c.orig	2016-06-05 07:12:06 UTC
+++ spectrwm.c
@@ -7876,7 +7876,7 @@ validate_spawns(void)
 void
 setup_spawn(void)
 {
-	setconfspawn("lock",		"xlock",		0);
+	setconfspawn("lock",		"xlock",		SWM_SPAWN_OPTIONAL);
 
 	setconfspawn("term",		"xterm",		0);
 	setconfspawn("spawn_term",	"xterm",		0);
