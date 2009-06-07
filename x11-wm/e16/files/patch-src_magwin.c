--- src/magwin.c.orig	2009-06-08 00:24:00.000000000 +0200
+++ src/magwin.c	2009-06-08 00:24:18.000000000 +0200
@@ -448,8 +448,6 @@
 #if USE_TIMER
    TIMER_DEL(mw->timer);
 #endif
-   EventCallbackUnregister(EwinGetClientWin(mw->ewin), 0, MagwinEvent, mw);
-   EDestroyWindow(EwinGetClientWin(mw->ewin));
    Efree(mw);
 }
 
