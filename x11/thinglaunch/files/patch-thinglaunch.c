--- thinglaunch.c.orig	2004-09-20 16:27:56.000000000 +0200
+++ thinglaunch.c	2009-09-01 22:11:10.000000000 +0200
@@ -19,10 +19,14 @@
  */
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
+#include <X11/keysymdef.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
 
 static void createWindow();
 static void setupGC();
@@ -50,10 +54,13 @@
 
 /* the actual commandline */
 char command[MAXCMD+1];
+size_t cursor_pos;
 
 int main(int argc, char ** argv) {
 
 	command[0] = 0x0;
+	cursor_pos = 0;
+
 	createWindow();
 
 	setupGC();
@@ -209,15 +216,15 @@
 
 	int font_height;
 	int textwidth;
-	
+
 	font_height = font_info->ascent + font_info->descent;
-	textwidth = XTextWidth(font_info, command, strlen(command));
+	textwidth = XTextWidth(font_info, command, cursor_pos);
 
 	XFillRectangle(display, win, rectgc, 0, 0, WINWIDTH, WINHEIGHT);
 	XDrawRectangle(display, win, gc, 0, 0, WINWIDTH-1, WINHEIGHT-1);
 	XDrawString(display, win, gc, 2, font_height+2, command, strlen(command));
-	XDrawLine(display, win, gc, 2 + textwidth, font_height + 2,
-			2 + textwidth + 10, font_height+2);
+	XDrawLine(display, win, gc, 2 + textwidth, font_height + 4,
+			2 + textwidth + 10, font_height+4);
 
 	XFlush(display);
 
@@ -229,22 +236,36 @@
 #define KEYBUFLEN 20
 	char buffer[KEYBUFLEN+1];
 	KeySym key_symbol;
-	int len;
+	int len, tmp_pos;
 
 	len = XLookupString(keyevent, buffer, 1, &key_symbol, NULL);
 	buffer[len] = 0x0;
+	len = strlen(command);
 
 	switch(key_symbol) {
-		case 0xff1b: /* this is escape */
+		case XK_Escape:
 			exit(0);
 			break;
-		case 0xff08: /* backspace */
-			len = strlen(command);
-			if (len > 0) {
-				command[len-1] = 0x0;
-			}
+		case XK_BackSpace:
+			if (cursor_pos)
+			    for (tmp_pos = --cursor_pos; tmp_pos <= len; tmp_pos++)
+				command[tmp_pos] = command[tmp_pos+1];
+			break;
+		case XK_Left:
+			if (cursor_pos)
+			    cursor_pos--;
+			break;
+		case XK_Right:
+			if (cursor_pos < len)
+			    cursor_pos++;
+			break;
+		case XK_Home:
+			cursor_pos = 0;
+			break;
+		case XK_End:
+			cursor_pos = len;
 			break;
-		case 0xff0d: /* enter */
+		case XK_Return:
 			execcmd();
 			break;
 		default:
@@ -253,10 +274,11 @@
 
 	/* normal printable chars */
 	if (key_symbol >= 0x20 && key_symbol <= 0x7e) {
-		len = strlen(command);
 		if (len < MAXCMD) {
-			command[len] = buffer[0];
-			command[len+1] = 0x0;
+		    if (cursor_pos != len)
+			for (tmp_pos = len; tmp_pos > cursor_pos; tmp_pos--)
+			    command[tmp_pos] = command[tmp_pos-1];
+		    command[cursor_pos++] = buffer[0];
 		}
 	}
 	redraw();
