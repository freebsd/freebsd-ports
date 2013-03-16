--- src/nvidia_subr.c.orig	2013-01-14 14:38:44.000000000 -0800
+++ src/nvidia_subr.c	2013-03-09 06:47:05.000000000 -0800
@@ -83,7 +83,7 @@
             if (!sc->BAR_objects[i])
                 goto failed;
 
-            VM_OBJECT_LOCK(sc->BAR_objects[i]);
+            VM_OBJECT_WLOCK(sc->BAR_objects[i]);
             switch (i) {
                 case NV_GPU_BAR_INDEX_FB:
                     vm_object_set_memattr(sc->BAR_objects[i],
@@ -95,7 +95,7 @@
                             VM_MEMATTR_UNCACHEABLE);
                     break;
             }
-            VM_OBJECT_UNLOCK(sc->BAR_objects[i]);
+            VM_OBJECT_WUNLOCK(sc->BAR_objects[i]);
         }
     }
 
@@ -541,9 +541,9 @@
                 goto failed;
             }
 
-            VM_OBJECT_LOCK(sc->UD_object);
+            VM_OBJECT_WLOCK(sc->UD_object);
             vm_object_set_memattr(sc->UD_object, VM_MEMATTR_UNCACHEABLE);
-            VM_OBJECT_UNLOCK(sc->UD_object);
+            VM_OBJECT_WUNLOCK(sc->UD_object);
         }
 
         nv->flags |= NV_FLAG_OPEN;
@@ -965,9 +965,9 @@
         goto failed;
     }
 
-    VM_OBJECT_LOCK(at->object);
+    VM_OBJECT_WLOCK(at->object);
     vm_object_set_memattr(at->object, attr);
-    VM_OBJECT_UNLOCK(at->object);
+    VM_OBJECT_WUNLOCK(at->object);
 
     *private = at;
     SLIST_INSERT_HEAD(&sc->alloc_list, at, list);
@@ -1108,9 +1108,9 @@
         goto failed;
     }
 
-    VM_OBJECT_LOCK(at->object);
+    VM_OBJECT_WLOCK(at->object);
     vm_object_set_memattr(at->object, attr);
-    VM_OBJECT_UNLOCK(at->object);
+    VM_OBJECT_WUNLOCK(at->object);
 
     *private = at;
     SLIST_INSERT_HEAD(&sc->alloc_list, at, list);
