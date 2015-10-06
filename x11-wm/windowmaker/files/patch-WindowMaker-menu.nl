--- WindowMaker/menu.nl.orig	2015-08-11 18:41:14 UTC
+++ WindowMaker/menu.nl
@@ -208,7 +208,7 @@
 		"Achtergrond" END
 		"Thema opslaan" SHEXEC getstyle -t $HOME/GNUstep/Library/WindowMaker/Themes/"%a(Themanaam,Voer bestandsnaam in:)"
 		"Iconenset opslaan" SHEXEC geticonset $HOME/GNUstep/Library/WindowMaker/IconSets/"%a(Iconensetnaam,Voer bestandsnaam in:)"
-		"Voorkeurenhulpmiddel" EXEC /usr/local/GNUstep/Applications/WPrefs.app/WPrefs
+		"Voorkeurenhulpmiddel" EXEC PREFIX/GNUstep/Applications/WPrefs.app/WPrefs
 	"Uiterlijk" END
 
 	"Sessie" MENU
