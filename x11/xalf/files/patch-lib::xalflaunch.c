
$FreeBSD$

--- lib/xalflaunch.c	2001/08/15 12:43:46	1.1
+++ lib/xalflaunch.c	2001/08/15 12:45:49
@@ -45,7 +45,7 @@
 static void _init(void) __attribute__ ((section (".init")));
 #endif /* __FreeBSD__ */
 
-#if defined __GNUC__ && ( ( __GNUC__ == 2 ) && ( __GNUC_MINOR__ >= 96) || ( __GNUC__ >= 3) )
+#if ( defined __GNUC__ && ( ( __GNUC__ == 2 ) && ( __GNUC_MINOR__ >= 96) || ( __GNUC__ >= 3) ) ) || defined __FreeBSD__
 void initialize (void) __attribute__ ((constructor));
 void initialize (void)
 #else
