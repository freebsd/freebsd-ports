--- src/qml/configure.cmake.orig	2023-12-12 03:17:50 UTC
+++ src/qml/configure.cmake
@@ -96,8 +96,8 @@ qt_feature("qml-jit" PRIVATE
     AUTODETECT NOT IOS AND NOT TVOS
     CONDITION ( ( TEST_architecture_arch STREQUAL i386 AND QT_FEATURE_sse2 ) OR
         ( TEST_architecture_arch STREQUAL x86_64 AND QT_FEATURE_sse2 ) OR
-        ( TEST_architecture_arch STREQUAL arm AND TEST_arm_fp AND TEST_arm_thumb AND ( ANDROID OR LINUX OR IOS OR TVOS OR QNX ) ) OR
-        ( TEST_architecture_arch STREQUAL arm64 AND TEST_arm_fp AND ( ANDROID OR LINUX OR IOS OR TVOS OR QNX OR INTEGRITY ) ) )
+        ( TEST_architecture_arch STREQUAL arm AND TEST_arm_fp AND TEST_arm_thumb AND ( FREEBSD OR ANDROID OR LINUX OR IOS OR TVOS OR QNX ) ) OR
+        ( TEST_architecture_arch STREQUAL arm64 AND TEST_arm_fp AND ( FREEBSD OR ANDROID OR LINUX OR IOS OR TVOS OR QNX OR INTEGRITY ) ) )
 )
 # special case begin
 # When doing macOS universal builds, JIT needs to be disabled for the ARM slice.
