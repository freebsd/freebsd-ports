--- spectrwm.c.orig	2017-10-04 18:36:20 UTC
+++ spectrwm.c
@@ -7960,7 +7960,7 @@ validate_spawns(void)
 void
 setup_spawn(void)
 {
-	setconfspawn("lock",		"xlock",		0);
+	setconfspawn("lock",		"xlock",		SWM_SPAWN_OPTIONAL);
 
 	setconfspawn("term",		"xterm",		0);
 	setconfspawn("spawn_term",	"xterm",		0);
