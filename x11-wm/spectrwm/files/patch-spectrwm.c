--- spectrwm.c.orig	2020-06-17 19:26:40 UTC
+++ spectrwm.c
@@ -8913,7 +8913,7 @@ validate_spawns(void)
 void
 setup_spawn(void)
 {
-	setconfspawn("lock", "xlock", 0, NULL);
+	setconfspawn("lock", "xlock", SWM_SPAWN_OPTIONAL, NULL);
 
 	setconfspawn("term", "xterm", 0, NULL);
 	setconfspawn("spawn_term", "xterm", 0, NULL);
