Index: lib/X11/UIThrStubs.c
===================================================================
RCS file: /cvs/xorg/xc/lib/X11/UIThrStubs.c,v
retrieving revision 1.3
retrieving revision 1.4
diff -u -u -r1.3 -r1.4
--- lib/X11/UIThrStubs.c	28 May 2004 23:26:44 -0000	1.3
+++ lib/X11/UIThrStubs.c	13 Oct 2004 07:38:00 -0000	1.4
@@ -99,7 +99,7 @@
 #else
 #include <pthread.h>
 typedef pthread_t xthread_t;
-#if __GNUC__ >= 3
+#if __GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
 xthread_t pthread_self()    __attribute__ ((weak, alias ("_Xthr_self_stub_")));
 int pthread_mutex_init()    __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
 int pthread_mutex_destroy() __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
