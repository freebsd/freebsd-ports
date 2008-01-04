--- src/screen.c.orig	2003-03-23 17:56:06.000000000 +0100
+++ src/screen.c	2008-01-04 16:45:00.000000000 +0100
@@ -3548,7 +3548,7 @@
 	/* TODO: Handle MULTIPLE */
     } else if (rq->target == r->h->xa[XA_TIMESTAMP] && r->selection.text) {
 	XChangeProperty(r->Xdisplay, rq->requestor, rq->property, XA_INTEGER,
-			(8 * sizeof(Time)), PropModeReplace,
+			32, PropModeReplace,
 			(unsigned char *)&r->h->selection_time, 1);
 	ev.property = rq->property;
     } else if (rq->target == XA_STRING
