--- menu.c.orig	Fri Aug 14 20:35:05 1998
+++ menu.c	Fri Aug 14 22:28:13 1998
@@ -3148,7 +3148,8 @@
 	if (fDefault)
 	    state |= OLGX_DEFAULT;
 
-    if (pb->label[pb->which].kind == StringLabel)
+    if (pb->label[pb->which].kind == StringLabel ||
+	    pb->label[pb->which].kind == NoType)
 	label = pb->label[pb->which].string;
 #ifdef OLGX_LABEL_IS_COMB
     else if (pb->label[pb->which].kind == ComboLabel) {
