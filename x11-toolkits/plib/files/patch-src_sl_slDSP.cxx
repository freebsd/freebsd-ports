--- src/sl/slDSP.cxx.orig	2008-03-11 02:06:24.000000000 +0000
+++ src/sl/slDSP.cxx
@@ -413,7 +413,7 @@ void slDSP::stop ()
 /* NetBSD/OpenBSD 2.3 this should be very close to SUN Audio    */
 /* ------------------------------------------------------------ */
 
-#elif (defined(UL_BSD) && !defined(__FreeBSD__)) || defined(UL_SOLARIS)
+#elif (defined(UL_BSD) && !defined(__FreeBSD__) && !defined(__DragonFly__)) || defined(UL_SOLARIS)
 void slDSP::open ( const char *device, int _rate, int _stereo, int _bps )
 {
 
