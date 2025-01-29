--- lib/Factories/ItemFactory.vala.orig	2025-01-08 03:02:39 UTC
+++ lib/Factories/ItemFactory.vala
@@ -25,64 +25,50 @@ namespace Plank
 	public class ItemFactory : GLib.Object
 	{
 		const string[] DEFAULT_APP_WEB = {
-			"file:///usr/share/applications/chromium-browser.desktop",
-			"file:///usr/share/applications/google-chrome.desktop",
-			"file:///usr/share/applications/firefox.desktop",
-			"file:///usr/share/applications/epiphany.desktop",
-			"file:///usr/share/applications/midori.desktop",
-			"file:///usr/share/applications/kde4/konqbrowser.desktop"
+			"file://%%PREFIX%%/share/applications/chromium-browser.desktop",
+			"file://%%PREFIX%%/share/applications/firefox.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Epiphany.desktop"
 		};
 		
 		const string[] DEFAULT_APP_MAIL = {
-			"file:///usr/share/applications/thunderbird.desktop",
-			"file:///usr/share/applications/evolution.desktop",
-			"file:///usr/share/applications/geary.desktop",
-			"file:///usr/share/applications/kde4/KMail2.desktop"
+			"file://%%PREFIX%%/share/applications/thunderbird.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Evolution.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Geary.desktop",
+			"file://%%PREFIX%%/share/applications/org.kde.kmail2.desktop"
 		};
 		
 		const string[] DEFAULT_APP_CALENDAR = {
-			"file:///usr/share/applications/thunderbird.desktop",
-			"file:///usr/share/applications/evolution.desktop",
-			"file:///usr/share/applications/maya-calendar.desktop",
-			"file:///usr/share/applications/kde4/korganizer.desktop"
+			"file://%%PREFIX%%/share/applications/thunderbird.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Evolution.desktop",
+			"file://%%PREFIX%%/share/applications/org.kde.korganizer.desktop"
 		};
 		
 		const string[] DEFAULT_APP_TERMINAL = {
-			"file:///usr/share/applications/terminator.desktop",
-			"file:///usr/share/applications/gnome-terminal.desktop",
-			"file:///usr/share/applications/pantheon-terminal.desktop",
-			"file:///usr/share/applications/kde4/konsole.desktop"
+			"file://%%PREFIX%%/share/applications/org.gnome.Terminal.desktop",
+			"file://%%PREFIX%%/share/applications/io.elementary.terminal.desktop",
+			"file://%%PREFIX%%/share/applications/org.kde.konsole.desktop"
 		};
 		
 		const string[] DEFAULT_APP_AUDIO = {
-			"file:///usr/share/applications/exaile.desktop",
-			"file:///usr/share/applications/songbird.desktop",
-			"file:///usr/share/applications/rhythmbox.desktop",
-			"file:///usr/share/applications/noise.desktop",
-			"file:///usr/share/applications/banshee-1.desktop",
-			"file:///usr/share/applications/kde4/amarok.desktop"
+			"file://%%PREFIX%%/share/applications/exaile.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Rhythmbox3.desktop"
 		};
 		
 		const string[] DEFAULT_APP_VIDEO = {
-			"file:///usr/share/applications/vlc.desktop",
-			"file:///usr/share/applications/totem.desktop",
-			"file:///usr/share/applications/audience.desktop",
-			"file:///usr/share/applications/kde4/amarok.desktop"
+			"file://%%PREFIX%%/share/applications/vlc.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Totem.desktop",
+			"file://%%PREFIX%%/share/applications/io.elementary.videos.desktop"
 		};
 		
 		const string[] DEFAULT_APP_PHOTO = {
-			"file:///usr/share/applications/eog.desktop",
-			"file:///usr/share/applications/gnome-photos.desktop",
-			"file:///usr/share/applications/org.gnome.Photos.desktop",
-			"file:///usr/share/applications/shotwell.desktop",
-			"file:///usr/share/applications/kde4/digikam.desktop"
+			"file://%%PREFIX%%/share/applications/org.gnome.eog.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Photos.desktop",
+			"file://%%PREFIX%%/share/applications/org.gnome.Shotwell.desktop",
+			"file://%%PREFIX%%/share/applications/org.kde.digikam.desktop"
 		};
 		
 		const string[] DEFAULT_APP_MESSENGER = {
-			"file:///usr/share/applications/pidgin.desktop",
-			"file:///usr/share/applications/empathy.desktop",
-			"file:///usr/share/applications/birdie.desktop",
-			"file:///usr/share/applications/kde4/kopete.desktop"
+			"file://%%PREFIX%%/share/applications/pidgin.desktop"
 		};
 		
 		/**
