--- src/common/parser.y.orig	Fri Jan  4 07:47:57 2002
+++ src/common/parser.y	Sat Dec 14 14:49:19 2002
@@ -98,6 +98,7 @@
                          free($1); }
 	|	arg1
 			{$$ = $1; }
+	;
 
 arg1	:	WORD
 			{$$ = wxmake_word($1); free($1);}
