--- src/vte.c.orig	Sun May  2 02:43:01 2004
+++ src/vte.c	Sun Oct 31 20:23:36 2004
@@ -105,14 +105,14 @@
 #define VTE_ADJUSTMENT_PRIORITY		G_PRIORITY_DEFAULT_IDLE
 #define VTE_INPUT_RETRY_PRIORITY	G_PRIORITY_HIGH
 #define VTE_INPUT_PRIORITY		G_PRIORITY_DEFAULT_IDLE
-#define VTE_CHILD_INPUT_PRIORITY	G_PRIORITY_DEFAULT_IDLE
+#define VTE_CHILD_INPUT_PRIORITY	G_PRIORITY_LOW
 #define VTE_CHILD_OUTPUT_PRIORITY	G_PRIORITY_HIGH
 #define VTE_FX_PRIORITY			G_PRIORITY_DEFAULT_IDLE
 #define VTE_REGCOMP_FLAGS		REG_EXTENDED
 #define VTE_REGEXEC_FLAGS		0
 #define VTE_INPUT_CHUNK_SIZE		0x1000
 #define VTE_INVALID_BYTE		'?'
-#define VTE_COALESCE_TIMEOUT		2
+#define VTE_COALESCE_TIMEOUT		15	
 
 /* The structure we use to hold characters we're supposed to display -- this
  * includes any supported visible attributes. */
@@ -10534,9 +10534,13 @@
 static gint
 vte_terminal_visibility_notify(GtkWidget *widget, GdkEventVisibility *event)
 {
+	VteTerminal *terminal;
 	g_return_val_if_fail(GTK_WIDGET(widget), FALSE);
 	g_return_val_if_fail(VTE_IS_TERMINAL(widget), FALSE);
-	(VTE_TERMINAL(widget))->pvt->visibility_state = event->state;
+	terminal = VTE_TERMINAL(widget);
+	terminal->pvt->visibility_state = event->state;
+	if (terminal->pvt->visibility_state == GDK_VISIBILITY_UNOBSCURED)
+		vte_invalidate_all(terminal);
 	return FALSE;
 }
 
