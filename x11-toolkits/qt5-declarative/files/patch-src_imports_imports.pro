--- src/imports/imports.pro.orig	2021-12-17 11:51:57 UTC
+++ src/imports/imports.pro
@@ -24,7 +24,6 @@ qtHaveModule(quick) {
 
     qtConfig(quick-shadereffect): SUBDIRS += wavefrontmesh
 
-    qtHaveModule(testlib): SUBDIRS += testlib
     qtConfig(systemsemaphore): SUBDIRS += sharedimage
     qtConfig(quick-particles): \
         SUBDIRS += particles
