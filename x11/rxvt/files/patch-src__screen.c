--- src/screen.c.orig	2011-04-21 08:56:56.000000000 +0200
+++ src/screen.c	2011-04-21 08:59:19.000000000 +0200
@@ -3359,6 +3359,7 @@
     XEvent          ev;
     Atom32          target_list[4];
     Atom            target;
+    Atom            property;
     static Atom     xa_targets = None;
     static Atom     xa_compound_text = None;
     static Atom     xa_text = None;
@@ -3381,16 +3382,26 @@
     ev.xselection.target = rq->target;
     ev.xselection.time = rq->time;
 
+	/* ICCCM: 2.2. Responsibilities of the Selection Owner   
+	 * SelectionRequest:
+	 * If the specified property is None , the requestor
+	 * an obsolete client. Owners are encouraged
+	 * to support these clients by using the specified
+	 * target atom as the property name to be used for
+	 * the reply.
+	 */
+	property = (rq->property == 0) ? rq->target : rq->property;
+
     if (rq->target == xa_targets) {
 	target_list[0] = (Atom32) xa_targets;
 	target_list[1] = (Atom32) XA_STRING;
 	target_list[2] = (Atom32) xa_text;
 	target_list[3] = (Atom32) xa_compound_text;
-	XChangeProperty(Xdisplay, rq->requestor, rq->property, rq->target,
+	XChangeProperty(Xdisplay, rq->requestor, property, rq->target,
 			(8 * sizeof(target_list[0])), PropModeReplace,
 			(unsigned char *)target_list,
 			(sizeof(target_list) / sizeof(target_list[0])));
-	ev.xselection.property = rq->property;
+	ev.xselection.property = property;
     } else if (rq->target == XA_STRING
 	       || rq->target == xa_compound_text
 	       || rq->target == xa_text) {
@@ -3404,10 +3415,10 @@
 	}
 	cl[0] = selection.text;
 	XmbTextListToTextProperty(Xdisplay, cl, 1, style, &ct);
-	XChangeProperty(Xdisplay, rq->requestor, rq->property,
+	XChangeProperty(Xdisplay, rq->requestor, property,
 			target, 8, PropModeReplace,
 			ct.value, ct.nitems);
-	ev.xselection.property = rq->property;
+	ev.xselection.property = property;
     }
     XSendEvent(Xdisplay, rq->requestor, False, 0, &ev);
 }
