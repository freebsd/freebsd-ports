
$FreeBSD$

--- WINGs/findfile.c.orig	Thu Oct  4 06:39:17 2001
+++ WINGs/findfile.c	Thu Oct 25 11:14:56 2001
@@ -1,5 +1,5 @@
 /*
- *  Window Maker miscelaneous function library
+ *  Window Maker miscellaneous function library
  * 
  *  Copyright (c) 1997 Alfredo K. Kojima
  * 
@@ -226,7 +226,8 @@
 	    }
 	    wfree(fullpath);
 	}
-	tmp=&(tmp[len+1]);
+	tmp=&(tmp[len]);
+	if (*tmp==':') tmp++;
 	if (*tmp==0) break;
     }
     return NULL;
