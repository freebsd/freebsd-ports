--- src/include/functions.h.orig Thu Jul 20 11:08:52 2006
+++ src/include/functions.h  Thu Jul 20 11:08:52 2006
@@ -24,7 +24,7 @@
 char * firstword(char * word, int * offset);
 
 void savekeys(GtkButton *button, GtkBox ** boxes);
-void addkey(GtkWidget ** boxes);
+void addkey(GtkButton *button, GtkWidget ** boxes);
 GtkWidget * newkey(int Ctrl, int Alt, int Shift, int Win, 
                     GList * liste, char *value, char *touche, char *execcmd
                     );
