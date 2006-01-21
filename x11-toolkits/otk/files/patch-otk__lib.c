--- otk_lib.c.orig
+++ otk_lib.c
@@ -70,6 +70,7 @@
 
 #if (PLATFORM_KIND==Posix_Platform)
  // #include <unistd.h>
+ #include <sys/time.h>
  #define GlutEnabled 0	/* Choice: 0=Use X-windows, 1=Use Glut. */
  #define WinGLEnabled 0
  #ifndef SocEnabled
@@ -111,6 +112,7 @@
 #endif
 
 #include "otk_lib.h"
+#include "gadget_lib.h"
 
 int Otk_verbose=0;
 int OtkWindowSizeX=-1, OtkWindowSizeY=-1;
@@ -4517,3 +4519,5 @@
  glutMainLoop();
 #endif
 }
+
+#include "gadget_lib.c"
