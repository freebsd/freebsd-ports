--- src/command.C.orig	Mon Aug 16 09:13:25 2004
+++ src/command.C	Tue Aug 17 23:49:02 2004
@@ -51,6 +51,8 @@
 #include "command.h"
 
 #include <wchar.h>
+#include <sys/types.h>
+#include <signal.h>
 
 /*----------------------------------------------------------------------*/
 
@@ -4250,7 +4252,7 @@
     {
       if (v_buflen == 0)
         {
-          ssize_t written = write (pty.pty, data, min (len, MAX_PTY_WRITE));
+          ssize_t written = write (pty.pty, data, min (len, (unsigned int) MAX_PTY_WRITE));
 
           if ((unsigned int)written == len)
             return;
@@ -4268,7 +4270,7 @@
 
   for (;;)
     {
-      int written = write (pty.pty, v_buffer, min (MAX_PTY_WRITE, v_buflen));
+      int written = write (pty.pty, v_buffer, min ((unsigned int) MAX_PTY_WRITE, v_buflen));
 
       if (written > 0)
         {
