--- ./kdm/backend/printf.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/printf.c	Thu Apr 18 20:53:44 2002
@@ -65,7 +65,7 @@
  */
 
 /**************************************************************
- * (C) 2001 Oswald Buddenhagen <ossi@kde.org>
+ * (C) 2001-2002 Oswald Buddenhagen <ossi@kde.org>
  * Partially stolen from OpenSSH's OpenBSD compat directory.
  * (C) Patrick Powell, Brandon Long, Thomas Roessler, 
  *     Michael Elkins, Ben Lindstrom
@@ -507,23 +507,24 @@
 #ifdef USE_SYSLOG
     syslog (LOG_CRIT, "Out of memory in %s()", fkt);
 #else
-    char dbuf[20];
+    int el;
+    char dbuf[24], sbuf[128];
     logTime (dbuf);
-    fprintf (stderr, "%s "
+    el = sprintf (sbuf, "%s "
 # ifdef LOG_NAME
 	LOG_NAME "[%ld]: Out of memory in %s()\n", dbuf, 
 # else
 	"%s[%ld]: Out of memory in %s()\n", dbuf, prog, 
 # endif
 	(long)getpid(), fkt);
-    fflush (stderr);
+    write (2, sbuf, el);
 #endif
 }
 
 typedef struct {
     char *buf;
     int clen, blen, type;
-    char lmbuf[100];
+    char lmbuf[128];
 } OCLBuf;
 
 static void
@@ -533,25 +534,11 @@
 #ifdef USE_SYSLOG
 	syslog (lognums[oclbp->type], "%.*s", oclbp->clen, oclbp->buf);
 #else
-	char dbuf[20];
-	logTime (dbuf);
-	fprintf (stderr, "%s "
-# ifdef LOG_NAME
-	    LOG_NAME  "[%ld] %s: %.*s\n", dbuf, 
-# else
-	    "%s[%ld] %s: %.*s\n", dbuf, prog, 
-# endif
-	    (long)getpid(), lognams[oclbp->type], oclbp->clen, oclbp->buf);
-	fflush (stderr);
+	oclbp->buf[oclbp->clen] = '\n';
+	write (2, oclbp->buf, oclbp->clen + 1);
 #endif
 	oclbp->clen = 0;
     }
-    if (oclbp->buf) {
-	if (oclbp->buf != oclbp->lmbuf)
-	    free (oclbp->buf);
-	oclbp->buf = 0;
-	oclbp->blen = 0;
-    }
 }
 
 static void
@@ -564,10 +551,17 @@
     if (c == '\n')
 	OutChLFlush (oclbp);
     else {
+#ifndef USE_SYSLOG
+	if (oclbp->clen >= oclbp->blen - 1) {
+#else
 	if (oclbp->clen >= oclbp->blen) {
-	    if (oclbp->buf == oclbp->lmbuf)
+#endif
+	    if (oclbp->buf == oclbp->lmbuf) {
 		OutChLFlush (oclbp);
-	    nlen = oclbp->blen * 3 / 2 + 100;
+		oclbp->buf = 0;
+		oclbp->blen = 0;
+	    }
+	    nlen = oclbp->blen * 3 / 2 + 128;
 	    nbuf = realloc (oclbp->buf, nlen);
 	    if (nbuf) {
 		oclbp->buf = nbuf;
@@ -579,6 +573,19 @@
 		oclbp->blen = sizeof(oclbp->lmbuf);
 	    }
 	}
+#ifndef USE_SYSLOG
+	if (!oclbp->clen) {
+	    char dbuf[24];
+	    logTime (dbuf);
+	    oclbp->clen = sprintf (oclbp->buf, "%s "
+# ifdef LOG_NAME
+		LOG_NAME "[%ld] %s: ", dbuf, 
+# else
+		"%s[%ld] %s: ", dbuf, prog, 
+# endif
+	    (long)getpid(), lognams[oclbp->type]);
+	}
+#endif
 	oclbp->buf[oclbp->clen++] = c;
     }
 }
@@ -586,13 +593,12 @@
 static void
 Logger (int type, const char *fmt, va_list args)
 {
-    static OCLBuf oclb;
+    OCLBuf oclb = { 0, 0, 0, type };
 
-    if (oclb.type != type) {
-	OutChLFlush (&oclb);
-	oclb.type = type;
-    }
     DoPr(OutChL, &oclb, fmt, args);
+    /* no flush, every message is supposed to be \n-terminated */
+    if (oclb.buf && oclb.buf != oclb.lmbuf)
+	free (oclb.buf);
 }
 
 #ifdef LOG_DEBUG_MASK
