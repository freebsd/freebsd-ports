--- WindowMaker/plmenu.pl.orig	2015-08-11 18:41:14 UTC
+++ WindowMaker/plmenu.pl
@@ -32,7 +32,7 @@
 			("LyX",                 EXEC, "lyx"),
   			("Ghostview",           EXEC, "gv %a(Gv,Wprowadz nazwe pliku *.ps *.pdf *.no:)"),
   			("XDvi",                EXEC, "xdvi %a(Xdvi,Wprowadz nazwe pliku *.dvi:)"),
-			("Acrobat",             EXEC, "/usr/local/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)"),
+			("Acrobat",             EXEC, PREFIX "/Acrobat3/bin/acroread %a(Acrobat,Wprowadz nazwe pliku *.pdf:)"),
 			("Xpdf",                EXEC, "xpdf %a(Xpdf,Wprowadz nazwe pliku *.pdf:)"),
 			("Arkusz kalkulacyjny", EXEC, "xspread")
 		),
