--- src/common/parser.y.orig	Wed Dec 18 21:06:41 2002
+++ src/common/parser.y	Wed Dec 18 21:06:48 2002
@@ -97,6 +97,7 @@
                          free($1); }
 	|	arg1
 			{$$ = $1; }
+	;
 
 arg1	:	WORD
 			{$$ = wxmake_word($1); free($1);}
