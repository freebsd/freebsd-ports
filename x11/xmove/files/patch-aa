--- xmove/main.c.org	Tue Oct 21 00:20:47 1997
+++ xmove/main.c	Fri Jan 16 00:24:41 1998
@@ -70,7 +70,7 @@
 /*static char *OfficialName P((char *name ));*/
 static void ResizeBuffer P((Buffer *buffer, long len));
 static char *SetDefaultServer P((char *server_name));
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 static void SignalURG P((int signum ));
 static void SignalPIPE P((int signum ));
 static void SignalINT P((int signum ));
@@ -1233,7 +1233,7 @@
 #endif
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalURG(int signum)
 #else
 SignalURG()
@@ -1243,7 +1243,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalPIPE(int signum)
 #else
 SignalPIPE()
@@ -1253,7 +1253,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalINT(int signum)
 #else
 SignalINT()
@@ -1264,7 +1264,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalQUIT(int signum)
 #else
 SignalQUIT()
@@ -1275,7 +1275,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalTERM(int signum)
 #else
 SignalTERM()
@@ -1286,7 +1286,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalTSTP(int signum)
 #else
 SignalTSTP()
@@ -1296,7 +1296,7 @@
 }
 
 static void
-#ifdef SVR4
+#if defined(SVR4) || defined(BSD)
 SignalCONT(int signum)
 #else
 SignalCONT()
