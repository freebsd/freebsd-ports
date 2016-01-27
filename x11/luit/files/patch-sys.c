--- sys.c.orig	2012-03-23 04:23:07 UTC
+++ sys.c
@@ -256,7 +256,7 @@ setRawTermios(void)
     rc = tcgetattr(0, &tio);
     if (rc < 0)
 	return rc;
-    tio.c_lflag &= (unsigned) ~(ECHO | ICANON | ISIG);
+    tio.c_lflag &= (unsigned) ~(ECHO | ICANON | IEXTEN | ISIG);
     tio.c_iflag &= (unsigned) ~(ICRNL | IXOFF | IXON | ISTRIP);
 #ifdef ONLCR
     tio.c_oflag &= (unsigned) ~ONLCR;
