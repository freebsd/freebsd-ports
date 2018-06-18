--- config.def.h.orig	2018-06-18 05:54:16 UTC
+++ config.def.h
@@ -178,6 +178,8 @@ static Shortcut shortcuts[] = {
 	{ TERMMOD,              XK_Y,           selpaste,       {.i =  0} },
 	{ TERMMOD,              XK_Num_Lock,    numlock,        {.i =  0} },
 	{ TERMMOD,              XK_I,           iso14755,       {.i =  0} },
+	{ ShiftMask,            XK_Page_Up,     kscrollup,      {.i = -1} },
+	{ ShiftMask,            XK_Page_Down,   kscrolldown,    {.i = -1} },
 };
 
 /*
