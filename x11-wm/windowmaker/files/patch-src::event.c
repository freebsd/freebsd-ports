--- src/event.c.orig	Tue Jan  8 22:45:13 2002
+++ src/event.c	Thu Jan 22 01:46:24 2004
@@ -402,8 +402,6 @@ handleDeadProcess(void *foo)
 static void
 saveTimestamp(XEvent *event)
 {
-    LastTimestamp = CurrentTime;
-
     switch (event->type) {
      case ButtonRelease:
      case ButtonPress:
