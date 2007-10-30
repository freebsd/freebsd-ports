--- src/nvidia_os.c.orig	2007-10-30 14:06:34.000000000 +0600
+++ src/nvidia_os.c	2007-10-30 14:09:02.000000000 +0600
@@ -550,7 +550,7 @@
         return status;
 
 #if __FreeBSD_version >= 500000
-    mtx_init(&mtx->mutex_mtx, "rm.mutex_mtx", NULL, MTX_SPIN | MTX_RECURSE);
+    mtx_init(&mtx->mutex_mtx, "rm.mutex_mtx", NULL, MTX_DEF | MTX_RECURSE);
     cv_init(&mtx->mutex_wait, "rm.mutex_wait");
 #else
     /*
@@ -587,13 +587,13 @@
     struct os_mutex *mtx = semaphore;
 
 #if __FreeBSD_version >= 500000
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt > 0)
         rm_disable_interrupts();
     mtx->refcnt--;
     if (mtx->refcnt < 0)
         cv_wait(&mtx->mutex_wait, &mtx->mutex_mtx);
-    mtx_unlock_spin(&mtx->mutex_mtx);
+    mtx_unlock(&mtx->mutex_mtx);
 #else
     int spl = splhigh();
     if (mtx->refcnt > 0)
@@ -611,14 +611,14 @@
     struct os_mutex *mtx = semaphore;
 
 #if __FreeBSD_version >= 500000
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt < 1) {
-        mtx_unlock_spin(&mtx->mutex_mtx);
+        mtx_unlock(&mtx->mutex_mtx);
         return FALSE;
     } else {
         rm_disable_interrupts();
         mtx->refcnt--;
-        mtx_unlock_spin(&mtx->mutex_mtx);
+        mtx_unlock(&mtx->mutex_mtx);
     }
 #else
     int spl = splhigh();
@@ -641,13 +641,13 @@
     struct os_mutex *mtx = semaphore;
 
 #if __FreeBSD_version >= 500000
-    mtx_lock_spin(&mtx->mutex_mtx);
+    mtx_lock(&mtx->mutex_mtx);
     if (mtx->refcnt < 0)
         cv_signal(&mtx->mutex_wait);
     if (!mtx->refcnt)
         rm_enable_interrupts();
     mtx->refcnt++;
-    mtx_unlock_spin(&mtx->mutex_mtx);
+    mtx_unlock(&mtx->mutex_mtx);
 #else
     int spl = splhigh();
     if (!mtx->refcnt)
