--- ./include/pgtimerobject.h.orig	Sat Jan  4 18:13:38 2003
+++ ./include/pgtimerobject.h	Tue Jun 20 19:37:34 2006
@@ -32,7 +32,7 @@
 #include "paragui.h"
 #include <map>
 
-typedef Uint32 PG_TimerID;
+typedef ptrdiff_t PG_TimerID;
 
 /**
 	@author Alexander Pipelka
