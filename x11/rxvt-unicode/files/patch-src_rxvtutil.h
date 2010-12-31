--- src/rxvtutil.h.orig	2010-08-25 04:07:15.000000000 +0200
+++ src/rxvtutil.h	2010-12-29 12:29:26.000000000 +0100
@@ -40,6 +40,7 @@
 # define THROW(x) throw x
 #endif
 
+#if defined(HAVE_SYS_BYTEORDER_H)
 extern class byteorder {
   static unsigned int e; // at least 32 bits
 public:
@@ -50,6 +51,7 @@
   static bool little_endian () { return e == 0x44332211; };
   static bool vax           () { return e == 0x44332211; };
 } byteorder;
+#endif
 
 // various utility functions
 template<typename T, typename U> static inline T    min    (T  a, U b) { return a < (T)b ? a : (T)b; }
