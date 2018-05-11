--- config.def.h.orig	2015-11-08 23:39:37.000000000 +0100
+++ config.def.h	2018-03-25 21:26:37.860145000 +0200
@@ -56,7 +56,11 @@
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
 static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
 static const char *termcmd[]  = { "st", NULL };
+static const char *incrvol[] = { "mixer", "vol", "+1:+1", NULL};
+static const char *decrvol[] = { "mixer", "vol", "-1:-1", NULL};
 
+#define XK_XF86AudioLowerVolume 0x1008ff11
+#define XK_XF86AudioRaiseVolume 0x1008ff13
 static Key keys[] = {
 	/* modifier                     key        function        argument */
 	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
@@ -92,6 +96,8 @@
 	TAGKEYS(                        XK_8,                      7)
 	TAGKEYS(                        XK_9,                      8)
 	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
+	{ 0x0,                          XK_XF86AudioRaiseVolume,    spawn,           {.v = incrvol } },
+	{ 0x0,                          XK_XF86AudioLowerVolume,    spawn,           {.v = decrvol } },
 };
 
 /* button definitions */
