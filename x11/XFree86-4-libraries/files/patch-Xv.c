Index: lib/Xv/Xv.c
===================================================================
RCS file: /home/ncvs/xfree/xc/lib/Xv/Xv.c,v
retrieving revision 1.16
retrieving revision 1.17
diff -u -u -r1.16 -r1.17
--- lib/Xv/Xv.c	16 Oct 2002 00:37:33 -0000	1.16
+++ lib/Xv/Xv.c	28 Apr 2003 16:56:27 -0000	1.17
@@ -267,6 +267,7 @@
   *p_nAdaptors = rep.num_adaptors;
   *p_pAdaptors = pas;
 
+  Xfree(buffer);
   UnlockDisplay(dpy);
   SyncHandle();
 
