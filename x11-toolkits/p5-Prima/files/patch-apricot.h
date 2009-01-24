Index: apricot.h
===================================================================
RCS file: /pub/prima.eu.org/cvs/prima/Prima/include/apricot.h,v
retrieving revision 1.192
retrieving revision 1.193
diff -u -r1.192 -r1.193
--- include/apricot.h	28 Apr 2008 20:54:03 -0000	1.192
+++ include/apricot.h	6 Nov 2008 10:54:37 -0000	1.193
@@ -24,7 +24,7 @@
  * SUCH DAMAGE.
  */
 
-/* $Id: apricot.h,v 1.192 2008/04/28 20:54:03 dk Exp $ */
+/* $Id: apricot.h,v 1.193 2008/11/06 10:54:37 dk Exp $ */
 
 #ifndef _APRICOT_H_
 #define _APRICOT_H_
@@ -423,6 +423,10 @@
 
 /* Event structures */
 
+#ifdef KeyEvent
+#undef KeyEvent
+#endif
+
 typedef struct _KeyEvent {
    int    cmd;
    int    subcmd;
@@ -433,6 +437,10 @@
    int    repeat;
 } KeyEvent, *PKeyEvent;
 
+#ifdef PositionalEvent
+#undef PositionalEvent
+#endif
+
 typedef struct _PositionalEvent {
    int    cmd;
    int    subcmd;
@@ -443,6 +451,10 @@
    Bool   dblclk;
 } PositionalEvent, *PPositionalEvent;
 
+#ifdef GenericEvent
+#undef GenericEvent
+#endif
+
 typedef struct _GenericEvent {
    int    cmd;
    int    subcmd;
