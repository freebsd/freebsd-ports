--- src/nvidia-modeset/nvidia-modeset-freebsd.c.orig	2016-05-28 15:44:11 UTC
+++ src/nvidia-modeset/nvidia-modeset-freebsd.c
@@ -245,7 +245,7 @@ struct nvkms_ref_ptr {
 
 struct nvkms_ref_ptr* NVKMS_API_CALL nvkms_alloc_ref_ptr(void *ptr)
 {
-    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_FALSE);
+    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_TRUE);
     if (ref_ptr) {
         mtx_init(&ref_ptr->lock, "nvkms-ref-ptr-lock", NULL, MTX_SPIN);
         // The ref_ptr owner counts as a reference on the ref_ptr itself.
@@ -792,7 +792,7 @@ static int nvkms_open(
     nvkms_module.client_counter += 1;
     sx_xunlock(&nvkms_module.lock);
 
-    popen = nvkms_alloc(sizeof(*popen), NV_FALSE);
+    popen = nvkms_alloc(sizeof(*popen), NV_TRUE);
     if (popen == NULL) {
         return ENOMEM;
     }
