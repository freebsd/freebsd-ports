--- Frame.C.orig	2014-04-23 11:18:20.000000000 +0200
+++ Frame.C	2014-04-23 11:20:51.000000000 +0200
@@ -915,7 +915,7 @@
   // preserving stacking order:
   for (p = &first; *p;) {
     Frame* f = *p;
-    if (f == this || f->is_transient_for(this) && f->state() != UNMAPPED) {
+    if (f == this || (f->is_transient_for(this) && f->state() != UNMAPPED)) {
       *p = f->next; // remove it from list
       if (previous) {
 	XWindowChanges w;
@@ -970,7 +970,7 @@
 
 void Frame::iconize() {
   for (Frame* c = first; c; c = c->next) {
-    if (c == this || c->is_transient_for(this) && c->state() != UNMAPPED)
+    if (c == this || (c->is_transient_for(this) && c->state() != UNMAPPED))
       c->state(ICONIC);
   }
 }
@@ -1163,7 +1163,7 @@
 #endif
   }
   if (min_h == max_h || flag(KEEP_ASPECT|NO_RESIZE) ||
-      !max_h_button.value() && by+label_w+2*BUTTON_H > h()-BUTTON_BOTTOM) {
+      (!max_h_button.value() && by+label_w+2*BUTTON_H > h()-BUTTON_BOTTOM)) {
     max_h_button.hide();
   } else {
     max_h_button.position(BUTTON_LEFT,by);
@@ -1171,7 +1171,7 @@
     by += BUTTON_H;
   }
   if (min_w == max_w || flag(KEEP_ASPECT|NO_RESIZE) ||
-      !max_w_button.value() && by+label_w+2*BUTTON_H > h()-BUTTON_BOTTOM) {
+      (!max_w_button.value() && by+label_w+2*BUTTON_H > h()-BUTTON_BOTTOM)) {
     max_w_button.hide();
   } else {
     max_w_button.position(BUTTON_LEFT,by);
@@ -1653,8 +1653,8 @@
       else {ny = y(); nh = h();}
       if (flag(KEEP_ASPECT)) {
 	if (nw-dwidth > nh-dwidth
-	    && (what&(FL_ALIGN_LEFT|FL_ALIGN_RIGHT))
-	    || !(what&(FL_ALIGN_TOP|FL_ALIGN_BOTTOM)))
+	    && ((what&(FL_ALIGN_LEFT|FL_ALIGN_RIGHT))
+	    || !(what&(FL_ALIGN_TOP|FL_ALIGN_BOTTOM))))
 	  nh = nw-dwidth+dheight;
 	else
 	  nw = nh-dheight+dwidth;
