*** xgrabsc.c~	Mon Jun 28 18:14:49 1993
--- xgrabsc.c	Mon Feb 27 03:17:58 1995
***************
*** 246,251 ****
--- 246,252 ----
  int ScreenNumberOfScreen (scr)
      register Screen *scr;
  {
+ #ifdef BROKEN
      register Display *dpy = scr->display;
      register Screen *dpyscr = dpy->screens;
      register int i;
***************
*** 254,259 ****
--- 255,263 ----
  	if (scr == dpyscr) return i;
      }
      return -1;
+ #else
+     return XScreenNumberOfScreen (scr);
+ #endif
  }
  
  
