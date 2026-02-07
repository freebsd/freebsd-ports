--- ewmh.c.orig	2011-09-19 21:42:25 UTC
+++ ewmh.c
@@ -222,7 +222,7 @@ ewmh_process_state_atom(Client *c, Atom state, int set
 	CARD32 data[2];
 
 	data[1] = None;
-	if ((state == atom[WindowStateFs])) {
+	if ((state = atom[WindowStateFs])) {
 		focus(c);
 		if (set && !c->ismax) {
 			c->wasfloating = c->isfloating;
