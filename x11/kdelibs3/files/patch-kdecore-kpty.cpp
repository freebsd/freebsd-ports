--- kdecore/kpty.cpp
+++ kdecore/kpty.cpp
@@ -127,9 +127,15 @@
 #include <kdebug.h>
 #include <kstandarddirs.h>	// locate
 
-// not defined on HP-UX for example
-#undef CTRL
-#define CTRL(x) ((x) & 037)
+#ifndef CINTR
+#define CINTR	0x03
+#endif
+#ifndef CQUIT
+#define CQUIT	0x1c
+#endif
+#ifndef CERASE
+#define CERASE	0x7f
+#endif
 
 #define TTY_GROUP "tty"
 
@@ -333,9 +339,9 @@
     ttmode.c_iflag |= IUTF8;
 #endif
 
-  ttmode.c_cc[VINTR] = CTRL('C' - '@');
-  ttmode.c_cc[VQUIT] = CTRL('\\' - '@');
-  ttmode.c_cc[VERASE] = 0177;
+  ttmode.c_cc[VINTR] = CINTR;
+  ttmode.c_cc[VQUIT] = CQUIT;
+  ttmode.c_cc[VERASE] = CERASE;
 
   _tcsetattr(d->slaveFd, &ttmode);
 
