--- mpeg2dec/libvo/vroot.h.orig	Thu Dec 12 04:33:33 2002
+++ mpeg2dec/libvo/vroot.h	Sun Jan 25 00:42:03 2004
@@ -98,7 +98,11 @@
 					__SWM_VROOT, 0, 1, False, XA_WINDOW,
 					&actual_type, &actual_format,
 					&nitems, &bytesafter,
+#ifdef __FreeBSD__		
+					(void *)&newRoot) == Success
+#else
 					(unsigned char **) &newRoot) == Success
+#endif
 				    && newRoot) {
 				    root = *newRoot;
 				    break;
