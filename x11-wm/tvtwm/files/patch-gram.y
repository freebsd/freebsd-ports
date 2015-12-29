--- gram.y.orig	1993-11-22 20:10:49 UTC
+++ gram.y
@@ -79,7 +79,7 @@ unsigned int mods_used = (ShiftMask | Co
 extern int do_single_keyword(), do_string_keyword(), do_number_keyword();
 extern name_list **do_colorlist_keyword();
 extern int do_color_keyword(), do_string_savecolor();
-extern int yylineno;
+int yylineno;
 %}
 
 %union
