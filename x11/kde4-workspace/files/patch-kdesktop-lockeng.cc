--- kdesktop/lockeng.cc.orig	Fri Sep 26 11:28:03 2003
+++ kdesktop/lockeng.cc	Fri Sep 26 11:31:15 2003
@@ -277,6 +277,9 @@
 	    {
 	    if (!event->xkey.send_event && mXAutoLock && mState == Waiting)
     		mXAutoLock->keyPressed();
+		// don't further process key events that were received only because XAutoLock wants them
+		if (!event->xkey.send_event && mXAutoLock && !QWidget::find( event->xkey.window ))
+		    return true;
 	    break;
 	    }
 
