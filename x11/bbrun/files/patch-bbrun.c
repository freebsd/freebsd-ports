--- bbrun.c.orig	2004-02-13 01:24:59.000000000 +0100
+++ bbrun.c	2012-06-01 20:42:51.000000000 +0200
@@ -3,7 +3,11 @@
 #include <string.h>
 #include <getopt.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#else
 #include <linux/types.h>
+#endif
 #include <X11/xpm.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
@@ -20,7 +24,7 @@
 #define ADVANCED_WINDOW_ROWS 3
 #define ADVANCED_WINDOW_COLS 10
 
-#define u32 __u32
+#define u32 uintptr_t
 #define __DEBUG__ 0
 #define VERSION "1.6"
 
@@ -38,8 +42,8 @@ char historyFilename[MAXPATHLEN + 1];   
 
 // TOC = Table Of Contents, it is a dynamically allocated array of pointers to dynamically
 // allocated history items. 
-u32 *histTOC;				 // Always keep track of the beginning, this one is NEVER incremented.
-u32 *histTOC2;				 // We increment this one for each item
+u32 *histTOC  = NULL;				 // Always keep track of the beginning, this one is NEVER incremented.
+u32 *histTOC2 = NULL;				 // We increment this one for each item
 
 void parseArguments(int, char **);
 void execDialogInformation();
@@ -197,7 +201,7 @@ void readHistory(void) {
 
       item = malloc(strlen(buf));
       strncpy(item, buf, strlen(buf));
-      item[strlen(buf)- 1] = 0x0;			// Remove the newline char
+      item[strlen(buf)- 1] = '\0';			// Remove the newline char
 
       *histTOC2 = (u32) item;
     } else {
@@ -322,7 +326,7 @@ void writeHistory() 
 // Event handler for Ok and Cancel buttons
 void callback (GtkWidget * widget, gpointer data) 
 {
-  if ((char *) data == "ok") 
+  if ((strcmp(data, "ok")) == 0) 
     execDialogInformation();
 
   gtk_main_quit();
