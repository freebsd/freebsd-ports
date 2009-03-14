--- ./fvwm/events.c.orig	1994-11-15 14:02:39.000000000 +0000
+++ ./fvwm/events.c	2009-03-11 09:42:52.000000000 +0000
@@ -985,7 +985,7 @@
 	  (MouseEntry->Modifier == (modifier& (~LockMask)))))
 	{
 	  /* got a match, now process it */
-	  if (MouseEntry->func != (int)NULL)
+	  if (MouseEntry->func != 0)
 	    {
 	      Action = MouseEntry->item ? MouseEntry->item->action : NULL;
 	      ExecuteFunction(MouseEntry->func, Action, Event.xany.window, 
