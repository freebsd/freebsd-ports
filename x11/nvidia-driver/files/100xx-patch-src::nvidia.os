--- src/nvidia_os.c.orig	2007-07-24 21:06:12.000000000 +0200
+++ src/nvidia_os.c	2007-07-24 21:17:09.000000000 +0200
@@ -598,7 +598,7 @@
             != RM_OK))
         return status;
 
-    mtx_init(&mtx->mutex_mtx, "rm.mutex_mtx", NULL, MTX_SPIN | MTX_RECURSE);
+    mtx_init(&mtx->mutex_mtx, "rm.mutex_mtx", NULL, MTX_DEF | MTX_RECURSE);
     cv_init(&mtx->mutex_wait, "rm.mutex_wait");
 
     mtx->refcnt = 1;
@@ -624,13 +624,13 @@
 {
     struct os_mutex *mtx = semaphore;
 
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt > 0)
         rm_disable_interrupts(NULL);
     mtx->refcnt--;
     if (mtx->refcnt < 0)
         cv_wait(&mtx->mutex_wait, &mtx->mutex_mtx);
-    mtx_unlock_spin(&mtx->mutex_mtx);
+    mtx_unlock(&mtx->mutex_mtx);
 
     return RM_OK;
 }
@@ -639,14 +639,14 @@
 {
     struct os_mutex *mtx = semaphore;
 
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt < 1) {
-        mtx_unlock_spin(&mtx->mutex_mtx);
+        mtx_unlock(&mtx->mutex_mtx);
         return FALSE;
     } else {
         rm_disable_interrupts(NULL);
         mtx->refcnt--;
-        mtx_unlock_spin(&mtx->mutex_mtx);
+        mtx_unlock(&mtx->mutex_mtx);
     }
 
     return TRUE;
@@ -656,13 +656,13 @@
 {
     struct os_mutex *mtx = semaphore;
 
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt < 0)
         cv_signal(&mtx->mutex_wait);
     if (!mtx->refcnt)
         rm_enable_interrupts(NULL);
     mtx->refcnt++;
-    mtx_unlock_spin(&mtx->mutex_mtx);
+    mtx_unlock(&mtx->mutex_mtx);
 
     return RM_OK;
 }
