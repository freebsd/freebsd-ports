--- ./ewmh.c.orig	2011-09-03 13:09:18.000000000 +0200
+++ ./ewmh.c	2011-09-03 13:09:46.000000000 +0200
@@ -218,7 +218,7 @@
 	CARD32 data[2];
 
 	data[1] = None;
-	if ((state == atom[WindowStateFs])) {
+	if ((state = atom[WindowStateFs])) {
 		focus(c);
 		if (set && !c->ismax) {
 			c->wasfloating = c->isfloating;
