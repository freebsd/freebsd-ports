--- charproc.c.orig	2017-06-12 01:01:20 UTC
+++ charproc.c
@@ -1,4 +1,4 @@
-/* $XTermId: charproc.c,v 1.1487 2017/06/12 01:01:20 tom Exp $ */
+/* $XTermId: charproc.c,v 1.1488 2017/06/12 22:00:15 tom Exp $ */
 
 /*
  * Copyright 1999-2016,2017 by Thomas E. Dickey
@@ -3696,6 +3696,7 @@ doparsing(XtermWidget xw, unsigned c, st
 			    break;
 			}
 			break;
+# if OPT_REGIS_GRAPHICS
 		    case 3:	/* ReGIS geometry */
 			switch (GetParam(1)) {
 			case 1:	/* read */
@@ -3717,6 +3718,7 @@ doparsing(XtermWidget xw, unsigned c, st
 			    break;
 			}
 			break;
+#endif
 		    default:
 			TRACE(("DATA_ERROR: CASE_GRAPHICS_ATTRIBUTES request with unknown item parameter: %d\n",
 			       GetParam(0)));
