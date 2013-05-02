--- WindowMaker/menu.pl.orig	2013-05-03 03:12:25.000000000 +0900
+++ WindowMaker/menu.pl	2013-05-03 03:12:17.000000000 +0900
@@ -134,7 +134,7 @@
 			"LyX"                 EXEC lyx
   			"Ghostview"           EXEC gv %a(GhostView,Wprowadz nazwe pliku *.ps *.pdf *.no:)
   			"XDvi"                EXEC xdvi %a(XDvi,Wprowadz nazwe pliku *.dvi:)
-			"Acrobat"             EXEC /usr/local/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)
+			"Acrobat"             EXEC PREFIX/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)
 			"Xpdf"                EXEC xpdf %a(Xpdf,Wprowadz nazwe pliku *.pdf:)
 			"Arkusz kalkulacyjny" EXEC xspread
 		"Tekst" END
