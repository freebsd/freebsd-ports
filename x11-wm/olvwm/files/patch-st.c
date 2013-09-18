--- st.c.orig	2013-09-17 21:38:07.452239734 -0700
+++ st.c	2013-09-17 21:52:40.812590309 -0700
@@ -14,6 +14,7 @@
 #include "st.h"
 #include "mem.h"
 
+static rehash();
 
 #define max(a,b) ((a) > (b) ? (a) : (b))
 #define nil(type) ((type *) 0)
@@ -339,7 +340,7 @@
 		ptr = ptr->next;
 		break;
 	    case ST_STOP:
-		return;
+		return 0;
 	    case ST_DELETE:
 		tmp = ptr;
 		if (last == nil(st_table_entry)) {
