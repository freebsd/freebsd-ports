--- src/command.C.orig	Wed Dec  1 01:41:39 2004
+++ src/command.C	Wed Dec  1 21:25:37 2004
@@ -51,6 +51,8 @@
 #include "command.h"
 
 #include <wchar.h>
+#include <sys/param.h>
+#include <sys/types.h>
 #include <signal.h>
 
 /*----------------------------------------------------------------------*/
@@ -2698,7 +2700,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
@@ -4296,7 +4300,7 @@
     {
       if (v_buflen == 0)
         {
-          ssize_t written = write (pty.pty, data, min (len, MAX_PTY_WRITE));
+          ssize_t written = write (pty.pty, data, min (len, (unsigned int) MAX_PTY_WRITE));
 
           if ((unsigned int)written == len)
             return;
@@ -4314,7 +4318,7 @@
 
   for (;;)
     {
-      int written = write (pty.pty, v_buffer, min (v_buflen, MAX_PTY_WRITE));
+      int written = write (pty.pty, v_buffer, min (v_buflen, (unsigned int) MAX_PTY_WRITE));
 
       if (written > 0)
         {
