--- ./kdm/backend/dm.h.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/dm.h	Thu Apr 18 20:53:44 2002
@@ -72,6 +72,9 @@
 # include <X11/Xdmcp.h>
 #endif
 
+#ifdef CSRG_BASED
+# include <sys/param.h>
+#endif
 #ifdef pegasus
 # undef dirty		/* Some bozo put a macro called dirty in sys/param.h */
 #endif
