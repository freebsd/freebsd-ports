--- WindowMaker/menu.pl.orig	2015-08-11 18:41:14 UTC
+++ WindowMaker/menu.pl
@@ -134,7 +134,7 @@
 			"LyX"                 EXEC lyx
   			"Ghostview"           EXEC gv %a(GhostView,Wprowadz nazwe pliku *.ps *.pdf *.no:)
   			"XDvi"                EXEC xdvi %a(XDvi,Wprowadz nazwe pliku *.dvi:)
-			"Acrobat"             EXEC /usr/local/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)
+			"Acrobat"             EXEC PREFIX/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)
 			"Xpdf"                EXEC xpdf %a(Xpdf,Wprowadz nazwe pliku *.pdf:)
 			"Arkusz kalkulacyjny" EXEC xspread
 		"Tekst" END
