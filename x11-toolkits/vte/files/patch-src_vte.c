--- src/vte.c.orig	Mon Jun 16 17:15:09 2003
+++ src/vte.c	Thu Apr  8 14:24:13 2004
@@ -101,7 +101,7 @@
 #define VTE_ADJUSTMENT_PRIORITY		G_PRIORITY_DEFAULT_IDLE
 #define VTE_INPUT_RETRY_PRIORITY	G_PRIORITY_HIGH
 #define VTE_INPUT_PRIORITY		G_PRIORITY_DEFAULT_IDLE
-#define VTE_CHILD_INPUT_PRIORITY	G_PRIORITY_DEFAULT_IDLE
+#define VTE_CHILD_INPUT_PRIORITY	G_PRIORITY_LOW
 #define VTE_CHILD_OUTPUT_PRIORITY	G_PRIORITY_HIGH
 #define VTE_FX_PRIORITY			G_PRIORITY_DEFAULT_IDLE
 #define VTE_REGCOMP_FLAGS		REG_EXTENDED
@@ -109,7 +109,7 @@
 #define VTE_INPUT_CHUNK_SIZE		0x1000
 #define VTE_INVALID_SOURCE		-1
 #define VTE_INVALID_BYTE		'?'
-#define VTE_COALESCE_TIMEOUT		2
+#define VTE_COALESCE_TIMEOUT		50
 
 /* The structure we use to hold characters we're supposed to display -- this
  * includes any supported visible attributes. */
@@ -11318,7 +11318,6 @@
 						     terminal);
 		g_object_unref(G_OBJECT(terminal->pvt->pty_reaper));
 	}
-	terminal->pvt->pty_pid = -1;
 	terminal->pvt->pty_reaper = NULL;
 
 	/* Stop processing input. */
