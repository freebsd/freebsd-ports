--- kitty/gl-wrapper.h.orig	2022-11-07 10:06:42 UTC
+++ kitty/gl-wrapper.h
@@ -6146,7 +6146,7 @@ int gladLoadGLUserPtr( GLADuserptrloadfunc load, void 
 int gladLoadGL( GLADloadfunc load) {
     return gladLoadGLUserPtr( glad_gl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
 }
-void gladInstallGLDebug() {
+void gladInstallGLDebug(void) {
     glad_debug_glActiveTexture = glad_debug_impl_glActiveTexture;
     glad_debug_glAttachShader = glad_debug_impl_glAttachShader;
     glad_debug_glBeginConditionalRender = glad_debug_impl_glBeginConditionalRender;
@@ -6517,7 +6517,7 @@ void gladInstallGLDebug() {
     glad_debug_glViewport = glad_debug_impl_glViewport;
     glad_debug_glWaitSync = glad_debug_impl_glWaitSync;
 }
-void gladUninstallGLDebug() {
+void gladUninstallGLDebug(void) {
     glad_debug_glActiveTexture = glad_glActiveTexture;
     glad_debug_glAttachShader = glad_glAttachShader;
     glad_debug_glBeginConditionalRender = glad_glBeginConditionalRender;
