--- src/ssg/ssg.cxx.orig	Mon Mar  3 11:25:56 2003
+++ src/ssg/ssg.cxx	Mon Mar  3 11:27:40 2003
@@ -35,6 +35,7 @@
 #  endif
 #endif
 
+#if 0
 static bool glIsValidContext ( void )
 {
 #if defined(CONSOLE)
@@ -49,6 +50,7 @@
   return ( glXGetCurrentContext () != NULL ) ;
 #endif
 }
+#endif
 
 sgMat4 _ssgOpenGLAxisSwapMatrix =
 {
@@ -105,10 +107,12 @@
 
 void ssgInit ()
 {
+#if 0
   if ( ! glIsValidContext () )
   {
     ulSetError ( UL_FATAL, "ssgInit called without a valid OpenGL context.");
   }
+#endif
 
   ssgTexturePath ( "." ) ;
   ssgModelPath   ( "." ) ;
