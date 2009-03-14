--- ./modules/FvwmAudio/FvwmAudio.c.orig	1994-09-14 14:28:53.000000000 +0000
+++ ./modules/FvwmAudio/FvwmAudio.c	2009-03-11 09:42:51.000000000 +0000
@@ -477,7 +477,7 @@
 
 	if (sound_table[sound])
 	{
-		memset(buf,NULL,BUFSIZE);
+		memset(buf, 0, sizeof(buf));
 
 		/*
 		 * Don't use audio_play_dir if it's NULL or if the sound file
