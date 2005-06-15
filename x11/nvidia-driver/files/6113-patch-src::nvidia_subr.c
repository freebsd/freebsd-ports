--- src/nvidia_subr.c.orig	Sat Feb 19 13:19:54 2005
+++ src/nvidia_subr.c	Sat Feb 19 13:22:47 2005
@@ -1115,10 +1115,15 @@
 
 #if __FreeBSD_version < 500000
         vm_page_wire(m);
+#else
+        VM_OBJECT_LOCK(m->object);
 #endif
         vm_page_lock_queues();
         vm_page_wakeup(m);
         vm_page_unlock_queues();
+#if __FreeBSD_version >= 500000
+        VM_OBJECT_UNLOCK(m->object);
+#endif
     }
 
     at->object = object;
