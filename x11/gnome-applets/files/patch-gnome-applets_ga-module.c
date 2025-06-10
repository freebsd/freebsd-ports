--- gnome-applets/ga-module.c.orig	2023-09-23 06:38:26 UTC
+++ gnome-applets/ga-module.c
@@ -34,8 +34,6 @@
 #include "gweather/gweather-applet.h"
 #include "inhibit/inhibit-applet.h"
 #include "mini-commander/mini-commander-applet.h"
-#include "multiload/multiload-applet.h"
-#include "netspeed/netspeed-applet.h"
 #include "sticky-notes/sticky-notes-applet.h"
 #include "timer/timer-applet.h"
 #ifdef HAVE_TRACKER_SEARCH_BAR
@@ -169,26 +167,6 @@ ga_get_applet_info (const char *id)
       about_func = mini_commander_applet_setup_about;
       help_uri = "help:command-line";
     }
-  else if (g_strcmp0 (id, "multiload") == 0)
-    {
-      type_func = multiload_applet_get_type;
-      name = _("System Monitor");
-      description = _("A system load indicator");
-      icon_name = "utilities-system-monitor";
-
-      about_func = multiload_applet_setup_about;
-      help_uri = "help:multiload";
-    }
-  else if (g_strcmp0 (id, "netspeed") == 0)
-    {
-      type_func = netspeed_applet_get_type;
-      name = _("Network Monitor");
-      description = _("Netspeed Applet");
-      icon_name = "netspeed-applet";
-
-      about_func = netspeed_applet_setup_about;
-      help_uri = "help:netspeed_applet";
-    }
   else if (g_strcmp0 (id, "sticky-notes") == 0)
     {
       type_func = sticky_notes_applet_get_type;
@@ -300,10 +278,6 @@ ga_get_applet_id_from_iid (const char *iid)
     return "inhibit";
   else if (g_strcmp0 (iid, "MiniCommanderAppletFactory::MiniCommanderApplet") == 0)
     return "mini-commander";
-  else if (g_strcmp0 (iid, "MultiLoadAppletFactory::MultiLoadApplet") == 0)
-    return "multiload";
-  else if (g_strcmp0 (iid, "NetspeedAppletFactory::NetspeedApplet") == 0)
-    return "netspeed";
   else if (g_strcmp0 (iid, "StickyNotesAppletFactory::StickyNotesApplet") == 0)
     return "sticky-notes";
   else if (g_strcmp0 (iid, "TimerAppletFactory::TimerApplet") == 0)
@@ -351,8 +325,6 @@ gp_module_load (GpModule *module)
                             "gweather",
                             "inhibit",
                             "mini-commander",
-                            "multiload",
-                            "netspeed",
                             "sticky-notes",
                             "timer",
 #ifdef HAVE_TRACKER_SEARCH_BAR
