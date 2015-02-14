Clang 3.6 is a lot stricter with some constraints.

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197201

http://llvm.org/viewvc/llvm-project?view=revision&revision=225244
http://lists.cs.uiuc.edu/pipermail/cfe-commits/Week-of-Mon-20150112/121309.html

--- pixman/pixman-mmx.c.orig	2014-04-24 08:34:14.000000000 +0400
+++ pixman/pixman-mmx.c	2015-01-30 20:19:28.000000000 +0300
@@ -89,7 +89,7 @@
     return __A;
 }
 
-#  ifdef __OPTIMIZE__
+#  if defined(__OPTIMIZE__) && !(defined (__clang__) && defined(__clang_major__) && defined(__clang_minor__) && __clang_major__ == 3 && __clang_minor__ >= 6)
 extern __inline __m64 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
 _mm_shuffle_pi16 (__m64 __A, int8_t const __N)
 {
