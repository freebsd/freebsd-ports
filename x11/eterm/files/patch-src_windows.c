
$FreeBSD$

--- src/windows.c.orig
+++ src/windows.c
@@ -467,9 +467,7 @@
         XClearWindow(Xdisplay, TermWin.vt);
     }
     XDefineCursor(Xdisplay, TermWin.vt, TermWin_cursor);
-    TermWin.mask = (KeyPressMask | EnterWindowMask | LeaveWindowMask | ExposureMask
-                    | ButtonPressMask | ButtonReleaseMask | Button1MotionMask
-                    | Button2MotionMask | Button3MotionMask);
+    TermWin.mask = (EnterWindowMask | LeaveWindowMask | ExposureMask | ButtonPressMask | ButtonReleaseMask | Button1MotionMask | Button2MotionMask | Button3MotionMask);
     XSelectInput(Xdisplay, TermWin.vt, TermWin.mask);
 
     /* If the user wants a specific desktop, tell the WM that */
