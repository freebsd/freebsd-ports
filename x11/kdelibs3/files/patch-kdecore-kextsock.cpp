Index: kdecore/kextsock.cpp
===================================================================
RCS file: /home/kde/kdelibs/kdecore/kextsock.cpp,v
retrieving revision 1.67
diff -u -3 -p -r1.67 kextsock.cpp
--- kdecore/kextsock.cpp	11 Dec 2003 22:54:36 -0000	1.67
+++ kdecore/kextsock.cpp	24 Jan 2004 17:48:28 -0000
@@ -85,6 +85,12 @@ extern "C" int res_init();
 #endif
 #define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
 
+#ifdef Q_OS_FREEBSD
+#ifndef EAI_NODATA
+#define EAI_NODATA EAI_NONAME
+#endif
+#endif
+
 //
 // Internal class definitions
 //
