--- src/aclass.c.orig	2009-06-08 00:26:06.000000000 +0200
+++ src/aclass.c	2009-06-08 00:28:04.000000000 +0200
@@ -937,7 +937,11 @@
       ewin->state.in_action = 1;
    EFunc(ewin, action->params);
    if (ewin)
-      ewin->state.in_action = 0;
+      {
+	 if (!EwinFindByPtr(ewin))
+	    return;              /* ewin has been destroyed */
+	 ewin->state.in_action = 0;
+      }
 
    /* Did we just hose ourselves? if so, we'd best not stick around here */
    if (mode_action_destroy)
