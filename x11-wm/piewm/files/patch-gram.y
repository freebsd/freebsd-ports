--- gram.y.orig	Thu Jan  1 15:33:42 1998
+++ gram.y	Thu Dec  9 23:31:00 1999
@@ -71,7 +71,7 @@
 extern int do_single_keyword(), do_string_keyword(), do_number_keyword();
 extern name_list **do_colorlist_keyword();
 extern int do_color_keyword();
-extern int yylineno;
+int yylineno;
 %}
 
 %union
