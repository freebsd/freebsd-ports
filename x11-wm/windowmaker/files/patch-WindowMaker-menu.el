--- WindowMaker/menu.el.orig	2013-05-03 03:12:26.000000000 +0900
+++ WindowMaker/menu.el	2013-05-03 03:12:17.000000000 +0900
@@ -139,7 +139,7 @@
 		"LyX" EXEC lyx
 		"Netscape" EXEC netscape 
   		"Ghostview" EXEC ghostview %a(Αρχείο προς ανάγνωση)
-		"Acrobat" EXEC /usr/local/Acrobat3/bin/acroread %a(Acrobar,Γράψε το PDF προς προβολή)
+		"Acrobat" EXEC PREFIX/Acrobat3/bin/acroread %a(Acrobar,Γράψε το PDF προς προβολή)
   		"TkDesk" EXEC tkdesk
 	"Προγράμματα" END
 	"Κειμενογράφοι" MENU
