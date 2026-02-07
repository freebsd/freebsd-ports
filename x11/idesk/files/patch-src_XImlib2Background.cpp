--- src/XImlib2Background.cpp	2025-04-28 14:47:32.419474000 -0700
+++ src/XImlib2Background.cpp	2025-04-28 14:48:10.152608000 -0700
@@ -26,6 +26,7 @@
 #include "Database.h"
 #include "XImlib2Background.h"
 #include <X11/Xatom.h>
+#include "sys/stat.h"
 
 XImlib2Background::XImlib2Background(AbstractContainer * c, AbstractConfig * con): TimerControl(), 
                                                     container(c), config(con),delay(0), mode(0),  save(NULL), show(NULL),
