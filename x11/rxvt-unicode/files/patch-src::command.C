--- src/command.C.orig	Wed Aug 25 05:45:20 2004
+++ src/command.C	Wed Aug 25 19:28:03 2004
@@ -51,6 +51,8 @@
 #include "command.h"
 
 #include <wchar.h>
+#include <sys/types.h>
+#include <signal.h>
 
 /*----------------------------------------------------------------------*/
 
@@ -4287,7 +4289,7 @@
     {
       if (v_buflen == 0)
         {
-          ssize_t written = write (pty.pty, data, min (len, MAX_PTY_WRITE));
+          ssize_t written = write (pty.pty, data, min (len, (unsigned int) MAX_PTY_WRITE));
 
           if ((unsigned int)written == len)
             return;
@@ -4305,7 +4307,7 @@
 
   for (;;)
     {
-      int written = write (pty.pty, v_buffer, min (v_buflen, MAX_PTY_WRITE));
+      int written = write (pty.pty, v_buffer, min (v_buflen, (unsigned int) MAX_PTY_WRITE));
 
       if (written > 0)
         {
