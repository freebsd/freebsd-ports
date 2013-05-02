--- WindowMaker/menu.sl.orig	2013-05-03 03:12:25.000000000 +0900
+++ WindowMaker/menu.sl	2013-05-03 03:12:17.000000000 +0900
@@ -125,7 +125,7 @@
 		"LyX" EXEC lyx
 		"Netscape" EXEC netscape 
   		"Ghostview" EXEC ghostview %a(Enter file to view)
-		"Acrobat" EXEC /usr/local/Acrobat3/bin/acroread %a(Enter PDF to view)
+		"Acrobat" EXEC PREFIX/Acrobat3/bin/acroread %a(Enter PDF to view)
   		"TkDesk" EXEC tkdesk
 	"Aplikacije" END
 	"Urejevalniki besedil" MENU
