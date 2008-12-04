--- src/misc.c.orig	2008-12-04 18:24:18.000000000 +0100
+++ src/misc.c	2008-12-04 18:25:48.000000000 +0100
@@ -227,11 +227,12 @@
 
 	nreq = (disp) ? NextRequest(disp) : 0;
 	fprintf(stdout, "[%d] %#8lx %4ld.%06ld [%3ld.%06ld]: ", getpid(),
-		nreq, tv1.tv_sec, tv1.tv_usec, tvd.tv_sec, tvd.tv_usec);
+		nreq, (unsigned long)tv1.tv_sec, tv1.tv_usec,
+		(unsigned long)tvd.tv_sec, tvd.tv_usec);
      }
    else
      {
-	fprintf(stdout, "[%d] %4ld.%06ld: ", getpid(), tv.tv_sec, tv.tv_usec);
+	fprintf(stdout, "[%d] %4ld.%06ld: ", getpid(), (unsigned long)tv.tv_sec, tv.tv_usec);
      }
 
    va_start(args, fmt);
