--- lib/XThrStub/UIThrStubs.c.old	Mon Nov 19 06:13:26 2001
+++ lib/XThrStub/UIThrStubs.c	Tue Jun  4 11:39:19 2002
@@ -99,6 +99,21 @@
 #else
 #include <pthread.h>
 typedef pthread_t xthread_t;
+#if __GNUC__ >= 3
+xthread_t pthread_self()    __attribute__ ((weak, alias ("_Xthr_self_stub_")));
+int pthread_mutex_init()    __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_mutex_destroy() __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_mutex_lock()    __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_mutex_unlock()  __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_cond_init()     __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_cond_destroy()  __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_cond_wait()     __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_cond_signal()   __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_cond_broadcast() __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_key_create()    __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+void *pthread_getspecific()  __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+int pthread_setspecific()   __attribute__ ((weak, alias ("_Xthr_zero_stub_")));
+#else	/* __GNUC__ */
 #pragma weak pthread_self = _Xthr_self_stub_
 #pragma weak pthread_mutex_init = _Xthr_zero_stub_
 #pragma weak pthread_mutex_destroy = _Xthr_zero_stub_
@@ -113,6 +128,7 @@
 #pragma weak pthread_key_create = _Xthr_zero_stub_
 #pragma weak pthread_getspecific = _Xthr_zero_stub_
 #pragma weak pthread_setspecific = _Xthr_zero_stub_
+#endif	/* __GNUC__ */
 #if defined(_DECTHREADS_) || defined(linux)
 #pragma weak pthread_equal = _Xthr_equal_stub_	/* See Xthreads.h! */
 int
