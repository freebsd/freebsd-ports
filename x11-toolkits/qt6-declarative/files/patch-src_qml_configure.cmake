--- src/qml/configure.cmake.orig	2023-07-26 19:30:31 UTC
+++ src/qml/configure.cmake
@@ -117,7 +117,7 @@ qt_feature("qml-jit" PRIVATE
     LABEL "QML just-in-time compiler"
     PURPOSE "Provides a JIT for QML and JavaScript"
     AUTODETECT NOT IOS AND NOT TVOS
-    CONDITION ( ( ( TEST_architecture_arch STREQUAL i386 ) AND TEST_pointer_32bit AND QT_FEATURE_sse2 ) OR ( ( TEST_architecture_arch STREQUAL x86_64 ) AND TEST_pointer_64bit AND QT_FEATURE_sse2 ) OR ( ( TEST_architecture_arch STREQUAL arm ) AND TEST_pointer_32bit AND TEST_arm_fp AND TEST_arm_thumb AND ( ANDROID OR LINUX OR IOS OR TVOS OR QNX ) ) OR ( ( TEST_architecture_arch STREQUAL arm64 ) AND TEST_pointer_64bit AND TEST_arm_fp AND ( ANDROID OR LINUX OR IOS OR TVOS OR QNX OR INTEGRITY ) ) )
+    CONDITION ( ( ( TEST_architecture_arch STREQUAL i386 ) AND TEST_pointer_32bit AND QT_FEATURE_sse2 ) OR ( ( TEST_architecture_arch STREQUAL x86_64 ) AND TEST_pointer_64bit AND QT_FEATURE_sse2 ) OR ( ( TEST_architecture_arch STREQUAL arm ) AND TEST_pointer_32bit AND TEST_arm_fp AND TEST_arm_thumb AND ( FREEBSD OR ANDROID OR LINUX OR IOS OR TVOS OR QNX ) ) OR ( ( TEST_architecture_arch STREQUAL arm64 ) AND TEST_pointer_64bit AND TEST_arm_fp AND ( FREEBSD OR ANDROID OR LINUX OR IOS OR TVOS OR QNX OR INTEGRITY ) ) )
 )
 # special case begin
 # When doing macOS universal builds, JIT needs to be disabled for the ARM slice.
