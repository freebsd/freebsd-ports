--- sip/qt/qstring.sip.orig	Sun Jan  9 20:06:08 2005
+++ sip/qt/qstring.sip	Sun Jan  9 20:06:25 2005
@@ -851,7 +851,7 @@
 		int len = PyUnicode_GET_SIZE(sipPy);
 
 		for (int i = 0; i < len; ++i)
-			qs->ref(i) = ucode[i];
+			qs->ref(i) = QChar(uint(ucode[i]));
 #else
 		qs -> setUnicodeCodes((ushort *)PyUnicode_AS_UNICODE(sipPy),PyUnicode_GET_SIZE(sipPy));
 #endif