--- lib/libxview/dnd/dnd_dsdm.c.orig	Thu Oct  5 18:16:17 2006
+++ lib/libxview/dnd/dnd_dsdm.c	Thu Oct  5 18:17:26 2006
@@ -40,7 +40,7 @@
     if (!dnd->sel) {
         Xv_object  	owner,
     			server;
-    	static void	ReplyProc();
+    	void	ReplyProc();
 
     	owner = (Xv_object)xv_get(DND_PUBLIC(dnd), XV_OWNER);
 
@@ -95,7 +95,7 @@
 }
 
 /* ARGSUSED */
-static void
+void
 ReplyProc(sel, target, type, buffer, length, format)
     Selection_requestor	 sel;
     Atom		 target, type;
