--- WindowMaker/menu.nl.orig	2014-08-30 21:29:09.000000000 +0900
+++ WindowMaker/menu.nl	2014-09-05 04:03:19.000000000 +0900
@@ -208,7 +208,7 @@
 		"Achtergrond" END
 		"Thema opslaan" SHEXEC getstyle -t $HOME/GNUstep/Library/WindowMaker/Themes/"%a(Themanaam,Voer bestandsnaam in:)"
 		"Iconenset opslaan" SHEXEC geticonset $HOME/GNUstep/Library/WindowMaker/IconSets/"%a(Iconensetnaam,Voer bestandsnaam in:)"
-		"Voorkeurenhulpmiddel" EXEC /usr/local/GNUstep/Applications/WPrefs.app/WPrefs
+		"Voorkeurenhulpmiddel" EXEC PREFIX/GNUstep/Applications/WPrefs.app/WPrefs
 	"Uiterlijk" END
 
 	"Sessie" MENU
