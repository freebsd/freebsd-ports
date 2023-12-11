--- config.def.h.orig	2023-12-11 13:41:28.765635000 +0300
+++ config.def.h	2023-12-11 13:46:14.977398000 +0300
@@ -58,7 +58,14 @@
 /* commands */
 static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
 static const char *termcmd[]  = { "st", NULL };
+static const char *incrvol[] = { "mixer", "vol.volume=+0.10", NULL };
+static const char *decrvol[] = { "mixer", "vol.volume=-0.10", NULL };
+static const char *mutevol[] = { "mixer", "vol.mute=^", NULL };
 
+#define XK_XF86AudioLowerVolume 0x1008ff11
+#define XK_XF86AudioMute	0x1008ff12
+#define XK_XF86AudioRaiseVolume 0x1008ff13
+
 static const Key keys[] = {
 	/* modifier                     key        function        argument */
 	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
@@ -94,6 +101,9 @@
 	TAGKEYS(                        XK_8,                      7)
 	TAGKEYS(                        XK_9,                      8)
 	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
+	{ 0x0,				XK_XF86AudioRaiseVolume,	spawn,	{.v = incrvol } },
+	{ 0x0,				XK_XF86AudioLowerVolume,	spawn,	{.v = decrvol } },
+	{ 0x0,				XK_XF86AudioMute,		spawn,	{.v = mutevol } },
 };
 
 /* button definitions */
