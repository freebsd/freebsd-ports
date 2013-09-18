--- virtual.c.orig	2013-09-17 21:38:07.402239496 -0700
+++ virtual.c	2013-09-17 21:56:18.620843579 -0700
@@ -39,15 +39,18 @@
 #define TRUE 1
 #define FALSE 0
 
-#include <regexp.h>
+#include <regex.h>
 #ifdef REGEXP
-regexp *expbuf;
+regex_t expbuf;
 #endif
 
 #ifdef IDENT
 #ident "@(#)virtual.c	1.6 olvwm version 07 Jan 1994"
 #endif
 
+static rexMatch();
+static rexInit();
+
 /* Class Function Vector; a virtual pane is the VDM window in which all
  * the little virtual windows appear (and to which said windows are
  * parented)
@@ -648,7 +651,7 @@
 XEvent	dummy;
 
     if (event->xexpose.count)
-	return;
+	return 0;
     drawVDMGrid(dpy, winInfo->core.client->scrInfo->vdm);
     while (XCheckTypedWindowEvent(dpy, event->xany.window, Expose, &dummy))
 	;	/* empty */
@@ -1324,7 +1327,7 @@
 	    length = ((WinPaneFrame *) win)->nameLength;
 	    break;
 	default:
-	    return;
+	    return 0;
     }
     XClearArea(cli->dpy, win->core.virtual, 0, 0, 0, 0, False);
     if (cli->isBusy)
@@ -2024,7 +2027,7 @@
 	    ErrorWarning(gettext("An invalid directory was named for DIRMENU"));
 	    menuInfo->buttons[bindex].subMenu =
 			MenuInfoCreate(cache, winInfo, menu, depth, slot);
-	    return;
+	    return 0;
 	}
     }
     while (ent = readdir(dir)) {
@@ -2108,14 +2111,16 @@
     }
 }
 
+#ifndef REGEXP
 static char expbuf[256];
+#endif
 
 static
 rexMatch(string)
     char *string;
 {
 #ifdef REGEXP
-    return regexec(expbuf, string);
+    return regexec(&expbuf, string, 0, NULL, 0);
 #else
     return step(string,expbuf);
 #endif
@@ -2152,7 +2157,7 @@
     newPattern[j++] = '$';
     newPattern[j++] = '\0';
 #ifdef REGEXP
-    expbuf = regcomp(newPattern);
+    regcomp(&expbuf, newPattern, 0);
 #else
     compile(newPattern, expbuf, &expbuf[256], '\0');
 #endif
