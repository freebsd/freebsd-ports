--- src/hints.h.orig	2007-03-11 14:44:43.000000000 +0100
+++ src/hints.h	2007-10-25 22:26:36.000000000 +0200
@@ -269,6 +269,7 @@
                                                                  int, 
                                                                  Window , 
                                                                  Window);
+void                     updateXserverTime                      (DisplayInfo *);
 Time                     getXServerTime                         (DisplayInfo *);
 
 #ifdef ENABLE_KDE_SYSTRAY_PROXY
