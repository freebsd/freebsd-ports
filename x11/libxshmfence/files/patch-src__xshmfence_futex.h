--- src/xshmfence_futex.h	2013-11-20 17:13:08.000000000 -0500
+++ src/xshmfence_futex.h	2013-12-09 15:52:29.000000000 -0500
@@ -1,5 +1,6 @@
 /*
  * Copyright © 2013 Keith Packard
+ * Copyright © 2013 Jung-uk Kim <jkim@FreeBSD.org>
  *
  * Permission to use, copy, modify, distribute, and sell this software and its
  * documentation for any purpose is hereby granted without fee, provided that
@@ -24,6 +25,27 @@
 #define _XSHMFENCE_FUTEX_H_
 
 #include <errno.h>
+
+#ifdef HAVE_UMTX
+
+#include <sys/types.h>
+#include <sys/umtx.h>
+
+static inline int sys_futex(void *addr, int op, int32_t val)
+{
+	return _umtx_op(addr, op, (uint32_t)val, NULL, NULL) == -1 ? errno : 0;
+}
+
+static inline int futex_wake(int32_t *addr) {
+	return sys_futex(addr, UMTX_OP_WAKE, INT_MAX);
+}
+
+static inline int futex_wait(int32_t *addr, int32_t value) {
+	return sys_futex(addr, UMTX_OP_WAIT_UINT, value);
+}
+
+#else
+
 #include <stdint.h>
 #include <values.h>
 #include <linux/futex.h>
@@ -43,6 +65,8 @@
 	return sys_futex(addr, FUTEX_WAIT, value, NULL, NULL, 0);
 }
 
+#endif
+
 #define barrier() __asm__ __volatile__("": : :"memory")
 
 static inline void atomic_store(int32_t *f, int32_t v)
