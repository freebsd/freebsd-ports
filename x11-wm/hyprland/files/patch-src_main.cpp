--- src/main.cpp.orig	2026-11-04 06:20:18 UTC
+++ src/main.cpp
@@ -256,7 +256,7 @@ int main(int argc, char** argv) {
 
 )#");
     }
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
     NInit::lowerAmbientCaps();
 #endif
     // let's init the compositor.
