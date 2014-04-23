--- Menu.C.orig	2014-04-23 11:21:07.000000000 +0200
+++ Menu.C	2014-04-23 11:21:32.000000000 +0200
@@ -560,7 +560,7 @@
       if (d == Desktop::current()) first_on_desk = menu+n;
       for (c = Frame::first; c; c = c->next) {
 	if (c->state() == UNMAPPED || c->transient_for()) continue;
-	if (c->desktop() == d || !c->desktop() && d == Desktop::current()) {
+	if (c->desktop() == d || (!c->desktop() && d == Desktop::current())) {
 	  init(menu[n],(char*)c);
 #if FL_MAJOR_VERSION < 2
 	  init(menu[n],(char*)c);
