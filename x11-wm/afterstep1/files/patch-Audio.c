--- modules/Audio/Audio.c.orig	1997-04-19 20:36:39 UTC
+++ modules/Audio/Audio.c
@@ -477,7 +477,7 @@ int audio_play(short sound) 
 
 	if (sound_table[sound])
 	{
-		memset(buf,NULL,BUFSIZE);
+		memset(buf,0,BUFSIZE);
 
 		/*
 		 * Don't use audio_play_dir if it's NULL or if the sound file
