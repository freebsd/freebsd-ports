--- src/dialogs/qfiledialog.cpp	Thu Nov  7 14:07:21 2002
+++ /cvs/qt-copy/src/dialogs/qfiledialog.cpp	Thu Nov 21 13:06:09 2002
@@ -3170,7 +3170,7 @@
 	    user = dr.mid( 1, i-1 ).local8Bit();
 	dr = dr.mid( i, dr.length() );
 	struct passwd *pw;
-#if defined(QT_THREAD_SUPPORT) && defined(_POSIX_THREAD_SAFE_FUNCTIONS)
+#if 0
 	struct passwd mt_pw;
 	char buffer[2048];
 	if ( ::getpwnam_r( user, &mt_pw, buffer, 2048, &pw ) == 0 && pw == &mt_pw )
