https://todo.sr.ht/~scoopta/wofi/211

--- src/wofi.c.orig	2024-02-04 23:26:21 UTC
+++ src/wofi.c
@@ -1299,13 +1299,10 @@ static void do_copy(void) {
 	}
 }
 
-static void on_exit_set_custom_key_return_code(int status, void* data) {
-	_UNUSED(data);
-	if (status == EXIT_SUCCESS) {
+static void atexit_set_custom_key_return_code(void) {
 		fflush(stdout);
 		fflush(stderr);
 		_exit(custom_key_return_code);
-	}
 }
 
 static void do_custom_key(int custom_key_num) {
@@ -2064,5 +2061,5 @@ void wofi_init(struct map* _config) {
 	gtk_window_set_title(GTK_WINDOW(window), prompt);
 	gtk_widget_show_all(window);
 
-	on_exit(on_exit_set_custom_key_return_code, NULL);
+	atexit(atexit_set_custom_key_return_code);
 }
