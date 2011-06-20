--- src/screen.c.orig	2003-03-23 17:56:06.000000000 +0100
+++ src/screen.c	2011-04-19 23:27:32.000000000 +0200
@@ -3520,6 +3520,7 @@
     Atom32          target_list[3];
 #endif
     Atom            target;
+    Atom            property;
     XTextProperty   ct;
     XICCEncodingStyle style;
     char           *cl[2], dummy[1];
@@ -3532,6 +3533,15 @@
     ev.target = rq->target;
     ev.time = rq->time;
 
+	/* ICCCM: 2.2. Responsibilities of the Selection Owner   
+	 * SelectionRequest:
+	 * If the specified property is None , the requestor
+	 * an obsolete client. Owners are encouraged
+	 * to support these clients by using the specified
+	 * target atom as the property name to be used for
+	 * the reply.
+	 */
+	property = (rq->property == 0) ? rq->target : rq->property;
     if (rq->target == r->h->xa[XA_TARGETS]) {
 	target_list[0] = (Atom32) r->h->xa[XA_TARGETS];
 	target_list[1] = (Atom32) XA_STRING;
@@ -3539,7 +3549,7 @@
 #ifdef USE_XIM
 	target_list[3] = (Atom32) r->h->xa[XA_COMPOUND_TEXT];
 #endif
-	XChangeProperty(r->Xdisplay, rq->requestor, rq->property, XA_ATOM,
+	XChangeProperty(r->Xdisplay, rq->requestor, property, XA_ATOM,
 			(8 * sizeof(target_list[0])), PropModeReplace,
 			(unsigned char *)target_list,
 			(sizeof(target_list) / sizeof(target_list[0])));
@@ -3547,10 +3557,10 @@
     } else if (rq->target == r->h->xa[XA_MULTIPLE]) {
 	/* TODO: Handle MULTIPLE */
     } else if (rq->target == r->h->xa[XA_TIMESTAMP] && r->selection.text) {
-	XChangeProperty(r->Xdisplay, rq->requestor, rq->property, XA_INTEGER,
-			(8 * sizeof(Time)), PropModeReplace,
+	XChangeProperty(r->Xdisplay, rq->requestor, property, XA_INTEGER,
+			32, PropModeReplace,
 			(unsigned char *)&r->h->selection_time, 1);
-	ev.property = rq->property;
+	ev.property = property;
     } else if (rq->target == XA_STRING
 	       || rq->target == r->h->xa[XA_COMPOUND_TEXT]
 	       || rq->target == r->h->xa[XA_TEXT]) {
@@ -3588,10 +3598,10 @@
 	    ct.value = (unsigned char *)cl[0];
 	    ct.nitems = selectlen;
 	}
-	XChangeProperty(r->Xdisplay, rq->requestor, rq->property,
+	XChangeProperty(r->Xdisplay, rq->requestor, property,
 			target, 8, PropModeReplace,
 			ct.value, (int)ct.nitems);
-	ev.property = rq->property;
+	ev.property = property;
 #ifdef USE_XIM
 	if (freect)
 	    XFree(ct.value);
