Add support for x11/budgie and fix x11/gnome-flashback,
x11/gnome-shell-extensions

--- lib/Services/Environment.vala.orig	2025-09-17 00:18:24 UTC
+++ lib/Services/Environment.vala
@@ -56,6 +56,7 @@ namespace Plank {
     PANTHEON = 1 << 11,
     DDE = 1 << 12,
     ENDLESS = 1 << 13,
+    BUDGIE = 1 << 14,
     OLD = 1 << 24,
     UBUNTU = 1 << 25;
 
@@ -66,7 +67,8 @@ namespace Plank {
       case "gnome": result = XdgSessionDesktop.GNOME; break;
       case "gnome-xorg": result = XdgSessionDesktop.GNOME; break;
       case "gnome-classic": result = XdgSessionDesktop.GNOME; break;
-      case "gnome-flashback": result = XdgSessionDesktop.GNOME; break;
+      case "gnome-classic-xorg": result = XdgSessionDesktop.GNOME; break;
+      case "gnome-flashback-metacity": result = XdgSessionDesktop.GNOME; break;
       case "ubuntu": result = XdgSessionDesktop.UBUNTU; break;
       case "ubuntu-xorg": result = XdgSessionDesktop.UBUNTU; break;
       case "kde": result = XdgSessionDesktop.KDE; break;
@@ -83,6 +85,7 @@ namespace Plank {
       case "cinnamon": result = XdgSessionDesktop.CINNAMON; break;
       case "pantheon": result = XdgSessionDesktop.PANTHEON; break;
       case "dde": result = XdgSessionDesktop.DDE; break;
+      case "budgie": result = XdgSessionDesktop.BUDGIE; break;
       case "endless": result = XdgSessionDesktop.ENDLESS; break;
       case "old": result = XdgSessionDesktop.OLD; break;
       default: result = XdgSessionDesktop.UNKNOWN; break;
