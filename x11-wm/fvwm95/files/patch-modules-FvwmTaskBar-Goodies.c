--- modules/FvwmTaskBar/Goodies.c.orig	Mon Sep  9 21:27:48 2002
+++ modules/FvwmTaskBar/Goodies.c	Mon Sep  9 21:28:44 2002
@@ -64,7 +64,9 @@
     if (strcasecmp(&tline[Clength+8], "None") == 0) {
       NoMailCheck = True;
     } else {
-      UpdateString(&mailpath, &tline[Clength+11]); 
+      /* UpdateString doesn't string spaces or newlines (and +11 is wrong) */
+      /* UpdateString(&mailpath, &tline[Clength+11]); */
+      CopyString(&mailpath, &tline[Clength+8]);
     }
   } else if(strncasecmp(tline,CatString3(Module, "ClockFormat",""),
 			  Clength+11)==0) {
