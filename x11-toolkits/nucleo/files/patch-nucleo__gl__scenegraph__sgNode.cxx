--- nucleo/gl/scenegraph/sgNode.cxx.orig
+++ nucleo/gl/scenegraph/sgNode.cxx
@@ -16,7 +16,10 @@
 #include <cmath>
 #include <cstring>
 
-#if defined (HAVE_TR1_UNORDERED_MAP)
+#if defined (_LIBCPP_VERSION)
+#include <unordered_map>
+typedef std::unordered_map<GLuint, void *> sgNodeMap;
+#elif defined (HAVE_TR1_UNORDERED_MAP)
 #include <tr1/unordered_map>
 typedef std::tr1::unordered_map<GLuint, void *> sgNodeMap;
 #elif defined (HAVE_EXT_HASH_MAP)
