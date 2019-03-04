--- musca_proto.h.orig	2009-11-03 02:20:21 UTC
+++ musca_proto.h
@@ -145,6 +145,7 @@ void head_focus(head *h);
 void head_next();
 void launch(char *cmd);
 void menu(char *cmd, char *after);
+void menufix(char *cmd, char *after);
 void menu_wrapper(char *cmd, char *after);
 void shutdown();
 dcell parse_size(char *cmd, regmatch_t *subs, ucell index, ucell limit);
