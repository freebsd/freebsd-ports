--- src/XImlib2Background.cpp.orig	2005-11-10 23:08:55 UTC
+++ src/XImlib2Background.cpp
@@ -26,6 +26,7 @@
 #include "Database.h"
 #include "XImlib2Background.h"
 #include <X11/Xatom.h>
+#include "sys/stat.h"
 
 XImlib2Background::XImlib2Background(AbstractContainer * c, AbstractConfig * con): TimerControl(), 
                                                     container(c), config(con),delay(0), mode(0),  save(NULL), show(NULL),
