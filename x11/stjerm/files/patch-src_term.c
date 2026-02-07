--- src/term.c~	2011-07-19 16:52:33.000000000 -0500
+++ src/term.c	2011-10-12 17:17:37.148128623 -0500
@@ -230,7 +230,7 @@ static void term_app_request(VteTerminal
 
 static void term_fork_command(VteTerminal *term, char *cmd)
 {
-    #if VTE_CHECK_VERSION(0,25,0)
+    #if 0
     char **argv = NULL;
     
     g_shell_parse_argv(cmd, NULL, &argv, NULL);
