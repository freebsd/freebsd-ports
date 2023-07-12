--- config.def.h.orig	2022-10-04 17:38:18 UTC
+++ config.def.h
@@ -58,7 +58,12 @@ static const Layout layouts[] = {
 /* commands */
 static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
 static const char *termcmd[]  = { "st", NULL };
+static const char *incrvol[] = { "mixer", "vol", "+1:+1", NULL };
+static const char *decrvol[] = { "mixer", "vol", "-1:-1", NULL };
 
+#define XK_XF86AudioLowerVolume 0x1008ff11
+#define XK_XF86AudioRaiseVolume 0x1008ff13
+
 static const Key keys[] = {
 	/* modifier                     key        function        argument */
 	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
@@ -94,6 +99,8 @@ static const Key keys[] = {
 	TAGKEYS(                        XK_8,                      7)
 	TAGKEYS(                        XK_9,                      8)
 	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
+	{ 0x0,                          XK_XF86AudioRaiseVolume,    spawn,           {.v = incrvol } },
+	{ 0x0,                          XK_XF86AudioLowerVolume,    spawn,           {.v = decrvol } },
 };
 
 /* button definitions */
