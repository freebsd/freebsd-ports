--- src/actions.c.orig	Tue Jul  2 09:30:25 2002
+++ src/actions.c	Thu Jan 22 01:45:57 2004
@@ -144,14 +144,22 @@ wSetFocusTo(WScreen *scr, WWindow  *wwin
       old_scr=scr;
     old_focused=old_scr->focused_window;
 
+    /*
+     * Safeguard: make sure the timestamp is monotonically increasing
+     * (very unlikely that this will be needed, still a safeguard)
+     */
+    if (timestamp <= LastFocusChange)
+           timestamp = LastFocusChange + 1;
+
+
     LastFocusChange = timestamp;
 
 /*
  * This is a hack, because XSetInputFocus() should have a proper
  * timestamp instead of CurrentTime but it seems that some times
  * clients will not receive focus properly that way.
+ */
     if (ignoreTimestamp)
-*/
       timestamp = CurrentTime;
 
     if (old_focused)
