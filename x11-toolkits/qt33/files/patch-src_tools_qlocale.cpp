--- src/tools/qlocale.cpp.orig2	Sat May 15 14:59:00 2004
+++ src/tools/qlocale.cpp	Sat May 15 15:10:21 2004
@@ -83,6 +83,11 @@
 static const bool ByteOrder = ((*((unsigned char *) &one) == 0) ? BigEndian : LittleEndian);
 #endif
 
+#if !defined(INFINITY) && defined(Q_OS_FREEBSD)
+#	define HUGE_VALF        (float)HUGE_VAL
+#	define INFINITY         HUGE_VALF
+#endif
+
 #if !defined(INFINITY)
 static const unsigned char be_inf_bytes[] = { 0x7f, 0xf0, 0, 0, 0, 0, 0, 0 };
 static const unsigned char le_inf_bytes[] = { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f };
