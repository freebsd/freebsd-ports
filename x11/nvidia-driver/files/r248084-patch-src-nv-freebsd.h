--- src/nv-freebsd.h.orig	2013-01-14 14:38:44.000000000 -0800
+++ src/nv-freebsd.h	2013-03-09 06:36:23.000000000 -0800
@@ -77,6 +77,7 @@
 #include <vm/vm_object.h>
 #include <vm/pmap.h>
 #include <vm/vm_map.h>
+#include <sys/rwlock.h>
 #include <vm/vm_pager.h>
 #include <vm/uma.h>
 
