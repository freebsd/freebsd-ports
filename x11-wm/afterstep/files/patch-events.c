--- afterstep/events.c.orig	1997-04-26 12:21:36 UTC
+++ afterstep/events.c
@@ -319,7 +319,7 @@ void HandleKeyPress()
        * same keysym and different keycodes. This converts all
        * the cases to one keycode. */
       Event.xkey.keycode = 
-	XKeysymToKeycode(dpy,XKeycodeToKeysym(dpy,Event.xkey.keycode,0));
+	XKeysymToKeycode(dpy,XkbKeycodeToKeysym(dpy,Event.xkey.keycode,0,0));
       if ((key->keycode == Event.xkey.keycode) &&
 	  ((key->mods == (modifier&(~LockMask)))||
 	   (key->mods == AnyModifier)) &&
@@ -558,7 +558,7 @@ void HandleExpose()
 	  ReallyRedrawPager();
 	}
 #endif
-      if ((Event.xany.window == Tmp_win->title_w))
+      if (Event.xany.window == Tmp_win->title_w)
 	{
 	  SetTitleBar(Tmp_win,(Scr.Hilite == Tmp_win),False);
 	}
