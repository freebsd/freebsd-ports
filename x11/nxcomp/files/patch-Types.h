Description: In Types.h, don't use STL internals on libc++.
Author: Clemens Lang <cal@macports.org>
Abstract:
 The nx-libs-lite package does not compile on OS X Mavericks because
 Apple's clang compilers now default to compiling against the libc++ STL
 rather than (their outdated copy of) libstdc++.
 .
 While the compiler still allows changing that, we should not rely on
 this being possible forever.
 .
 The compiler chokes in Types.h, specifically the clear() methods in
 subclasses of vectors that use implementation details of the GNU STL.
 The attached patch fixes these compilation issues by not overriding the
 clear() method when compiling against libc++, since the libc++ headers
 seem to do essentially the same as the overriden method.
--- Types.h	2013-11-05 01:35:22.000000000 +0100
+++ Types.h	2013-11-05 01:37:30.000000000 +0100
@@ -55,6 +55,9 @@
     return &*(vector < unsigned char >::begin());
   }
 
+  // Avoid overriding clear() when using libc++. Fiddling with STL internals
+  // doesn't really seem like a good idea to me anyway.
+  #ifndef _LIBCPP_VECTOR
   void clear()
   {
     #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H)
@@ -95,12 +98,16 @@
 
     #endif  /* #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H) */
   }
+  #endif /* #ifdef _LIBCPP_VECTOR */
 };
 
 class T_messages : public vector < Message * >
 {
   public:
 
+  // Avoid overriding clear() when using libc++. Fiddling with STL internals
+  // doesn't really seem like a good idea to me anyway.
+  #ifndef _LIBCPP_VECTOR
   void clear()
   {
     #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H)
@@ -141,6 +148,7 @@
 
     #endif /* #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H) */
   }
+  #endif /* #ifndef _LIBCPP_VECTOR */
 };
 
 typedef md5_byte_t * T_checksum;
