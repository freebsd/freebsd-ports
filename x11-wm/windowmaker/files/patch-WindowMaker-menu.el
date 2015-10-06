--- WindowMaker/menu.el.orig	2015-08-11 18:41:14 UTC
+++ WindowMaker/menu.el
@@ -139,7 +139,7 @@
 		"LyX" EXEC lyx
 		"Netscape" EXEC netscape 
   		"Ghostview" EXEC ghostview %a(Αρχείο προς ανάγνωση)
-		"Acrobat" EXEC /usr/local/Acrobat3/bin/acroread %a(Acrobar,Γράψε το PDF προς προβολή)
+		"Acrobat" EXEC PREFIX/Acrobat3/bin/acroread %a(Acrobar,Γράψε το PDF προς προβολή)
   		"TkDesk" EXEC tkdesk
 	"Προγράμματα" END
 	"Κειμενογράφοι" MENU
