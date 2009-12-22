--- src/vdkclist.cc.orig	2007-08-03 16:19:09.000000000 +0200
+++ src/vdkclist.cc	2007-08-03 16:20:09.000000000 +0200
@@ -26,7 +26,7 @@
  *
  */
 
-
+#include <sys/types.h>
 #include "vdk/vdkclist.h"
 #include "vdk/forms.h"
 #include <cstring>
@@ -377,7 +377,7 @@
       // load array;
       WideSelection = VDKIntArray(listSize);
       for(t = 0; t < WideSelection.size();t++,list = list->next)
-	WideSelection[t] = (int) list->data;
+	WideSelection[t] = (intptr_t) list->data;
     }
   return WideSelection;
 }
