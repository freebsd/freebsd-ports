Index: dm.c
===================================================================
RCS file: /home/kde/kdebase/kdm/backend/dm.c,v
retrieving revision 1.90.2.3
diff -u -3 -p -r1.90.2.3 dm.c
--- kdm/backend/dm.c	13 Aug 2004 19:21:11 -0000	1.90.2.3
+++ kdm/backend/dm.c	23 Aug 2004 16:32:29 -0000
@@ -1033,7 +1033,7 @@ static void
 MainLoop (void)
 {
     struct display *d;
-    struct timeval tv;
+    struct timeval *tvp, tv;
     time_t to;
     int nready;
     char buf;
@@ -1055,12 +1055,17 @@ MainLoop (void)
 	    to = serverTimeout;
 	if (utmpTimeout < to)
 	    to = utmpTimeout;
-	to -= now;
-	if (to < 0)
-	    to = 0;
-	tv.tv_sec = to;
-	tv.tv_usec = 0;
-	nready = select (WellKnownSocketsMax + 1, &reads, 0, 0, &tv);
+	if (to == TO_INF)
+	    tvp = 0;
+	else {
+	    to -= now;
+	    if (to < 0)
+		to = 0;
+	    tv.tv_sec = to;
+	    tv.tv_usec = 0;
+	    tvp = &to;
+	}
+	nready = select (WellKnownSocketsMax + 1, &reads, 0, 0, tvp);
 	Debug ("select returns %d\n", nready);
 	time (&now);
 #if !defined(ARC4_RANDOM) && !defined(DEV_RANDOM)
