diff -ruN ../ggiterm-0.5.1.bak/ggiterm.c ./ggiterm.c
--- ../ggiterm-0.5.1.bak/ggiterm.c	Mon Oct 20 18:04:02 2003
+++ ./ggiterm.c	Mon Oct 20 18:05:09 2003
@@ -18,13 +18,10 @@
 #include <signal.h>
 
 /* for forkpty */
-#ifdef HAVE_FORKPTY
-/* forkpty is in libc */
-#include <util.h>
-#else
-/* forkpty is in libutil */
-#include <pty.h>
-#endif /* HAVE_FORKPTY */
+#include <libutil.h>
+
+/* for struct winsize */
+#include <termios.h>
 
 /* for strcmp */
 #include <string.h>
