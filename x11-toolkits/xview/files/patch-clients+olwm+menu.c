--- ./clients/olwm/menu.c.orig	Tue Jun 29 07:11:50 1993
+++ ./clients/olwm/menu.c	Sat Apr  1 18:26:06 2000
@@ -52,6 +52,8 @@ static int  lastX, lastY, minX;
 static WinGeneric *prevColorFocusWindow = NULL;
 static MenuTrackMode menuTrackMode;
 
+static Bool isEnabled();
+
 /*
  * Table of currently active menus.
  * REMIND: perhaps this should be dynamically allocated.
