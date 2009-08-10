--- ./ksmserver/fadeeffect.cpp.ori	2008-07-22 00:15:47.000000000 +0200
+++ ./ksmserver/fadeeffect.cpp	2008-07-22 00:16:13.000000000 +0200
@@ -58,7 +58,7 @@
 #include "fadeeffect.moc"
 
 
-#ifndef HAVE_SSE2
+#if !defined(HAVE_SSE2) || __GNUC__ < 4
 static inline void *_mm_malloc(size_t size, int)
 {
     return malloc(size);
