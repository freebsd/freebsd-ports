--- src/nvidia_subr.c.orig	Wed Oct 30 15:30:58 2002
+++ src/nvidia_subr.c	Thu Mar  6 01:25:20 2003
@@ -925,7 +925,9 @@
          * prevent random crashes.
          */
         pa = vtophys((vm_offset_t) vm + (i * PAGE_SIZE));
+        vm_page_lock_queues();
         vm_page_wire(PHYS_TO_VM_PAGE(pa));
+        vm_page_unlock_queues();
     }
 
     at->object = 0;
@@ -963,6 +965,7 @@
     count = at->size / PAGE_SIZE;
     SLIST_REMOVE(&sc->alloc_list, at, nv_alloc, list);
 
+    vm_page_lock_queues();
     for (i = 0; i < count; i++) {
         /*
          * Release "one wiring" of this page; this may reenable paging as
@@ -971,6 +974,7 @@
         pa = vtophys(at->address + (i * PAGE_SIZE));
         vm_page_unwire(PHYS_TO_VM_PAGE(pa), 0);
     }
+    vm_page_unlock_queues();
 
     free(at, M_NVIDIA);
     free(address, M_NVIDIA);
@@ -1007,13 +1011,19 @@
          * will be allocated.
          */
 
+#if __FreeBSD_version < 500000
         m = vm_page_grab(object, i, VM_ALLOC_NORMAL);
+#else
+        m = vm_page_grab(object, i, VM_ALLOC_NORMAL | VM_ALLOC_WIRED);
+#endif
         if (!m) {
+            vm_page_lock_queues();
             for (i -= 1; i >= 0; i--) {
                 m = vm_page_lookup(object, i);
                 vm_page_wakeup(m);
                 vm_page_unwire(m, 0);
             }
+            vm_page_unlock_queues();
             return -ENOMEM;
         }
 
@@ -1022,7 +1032,9 @@
          * paging it out while we're still using it. This is necessary to
          * prevent random crashes.
          */
+#if __FreeBSD_version < 500000
         vm_page_wire(m);
+#endif
         vm_page_wakeup(m);
     }
 
@@ -1061,6 +1073,7 @@
     count = at->size / PAGE_SIZE;
     SLIST_REMOVE(&sc->alloc_list, at, nv_alloc, list);
 
+    vm_page_lock_queues();
     for (i = 0; i < count; i++) {
         /*
          * Release "one wiring" of this page; this may reenable paging as
@@ -1069,6 +1082,7 @@
         m = vm_page_lookup(at->object, i);
         vm_page_unwire(m, 0);
     }
+    vm_page_unlock_queues();
 
     free(at, M_NVIDIA);
     vm_object_deallocate(at->object);
@@ -1401,7 +1415,8 @@
 
 int nvidia_mmap_dev(
     struct nvidia_softc *sc,
-    vm_offset_t offset
+    vm_offset_t offset,
+    vm_offset_t *paddr
 )
 {
     nv_alloc_t *at;
@@ -1412,14 +1427,20 @@
      * are physical addresses and mapped into user-space directly. We can
      * only do some basic sanity checking here.
      */
-    if (IS_FB_OFFSET(nv, offset, PAGE_SIZE))
-        return atop(offset);
+    if (IS_FB_OFFSET(nv, offset, PAGE_SIZE)) {
+        *paddr = offset; 
+        return 0;
+    }
     
-    if (IS_REG_OFFSET(nv, offset, PAGE_SIZE))
-        return atop(offset);
+    if (IS_REG_OFFSET(nv, offset, PAGE_SIZE)) {
+        *paddr = offset; 
+        return 0;
+    }
     
-    if (IS_AGP_OFFSET(nv, offset, PAGE_SIZE))
-        return atop(offset);
+    if (IS_AGP_OFFSET(nv, offset, PAGE_SIZE)) {
+        *paddr = offset; 
+        return 0;
+    }
 
     /*
      * If the offset does not fall into any of the relevant apertures, we
@@ -1430,8 +1451,10 @@
      */
     SLIST_FOREACH(at, &sc->alloc_list, list) {
         if (offset >= at->address &&
-                offset < at->address + at->size)
-            return atop(vtophys(offset));
+                offset < at->address + at->size) {
+            *paddr = vtophys(offset);
+            return 0;
+        }
     }
 
     return -1;
