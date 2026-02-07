--- lib/Factories/ItemFactory.vala.orig	2025-08-28 03:55:28 UTC
+++ lib/Factories/ItemFactory.vala
@@ -23,95 +23,67 @@ namespace Plank {
    */
   public class ItemFactory : GLib.Object {
     const string[] DEFAULT_APP_WEB = {
-      "file:///usr/share/applications/brave-browser.desktop",
-      "file:///usr/share/applications/chromium-browser.desktop",
-      "file:///usr/share/applications/firefox.desktop",
-      "file:///usr/share/applications/org.mozilla.firefox.desktop",
-      "file:///var/lib/snapd/desktop/applications/firefox_firefox.desktop",
-      "file:///usr/share/applications/google-chrome.desktop",
-      "file:///usr/share/applications/epiphany.desktop",
-      "file:///usr/share/applications/midori.desktop",
-      "file:///usr/share/applications/kde4/konqbrowser.desktop"
+      "file://%%LOCALBASE%%/share/applications/chromium-browser.desktop",
+      "file://%%LOCALBASE%%/share/applications/firefox.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Epiphany.desktop",
     };
 
     const string[] DEFAULT_APP_MAIL = {
-      "file:///usr/share/applications/org.mozilla.Thunderbird.desktop",
-      "file:///usr/share/applications/thunderbird.desktop",
-      "file:///var/lib/snapd/desktop/applications/thunderbird_thunderbird.desktop",
-      "file:///usr/share/applications/evolution.desktop",
-      "file:///usr/share/applications/org.gnome.Evolution.desktop",
-      "file:///usr/share/applications/geary.desktop",
-      "file:///usr/share/applications/org.kde.kmail2.desktop",
-      "file:///usr/share/applications/kde4/KMail2.desktop"
+      "file://%%LOCALBASE%%/share/applications/thunderbird.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Evolution.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Geary.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.kmail2.desktop",
     };
 
     const string[] DEFAULT_APP_TERMINAL = {
-      "file:///usr/share/applications/com.mitchellh.ghostty.desktop",
-      "file:///usr/share/applications/kitty.desktop",
-      "file:///usr/share/applications/terminator.desktop",
-      "file:///usr/share/applications/org.gnome.Terminal.desktop",
-      "file:///usr/share/applications/gnome-terminal.desktop",
-      "file:///usr/share/applications/pantheon-terminal.desktop",
-      "file:///usr/share/applications/org.kde.konsole.desktop",
-      "file:///usr/share/applications/xfce4-terminal.desktop",
-      "file:///usr/share/applications/mate-terminal.desktop",
-      "file:///usr/share/applications/kde4/konsole.desktop",
-      "file:///usr/share/applications/xterm.desktop"
+      "file://%%LOCALBASE%%/share/applications/kitty.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Terminal.desktop",
+      "file://%%LOCALBASE%%/share/applications/io.elementary.terminal.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.konsole.desktop",
+      "file://%%LOCALBASE%%/share/applications/xfce4-terminal.desktop",
+      "file://%%LOCALBASE%%/share/applications/mate-terminal.desktop",
+      "file://%%LOCALBASE%%/share/applications/xterm.desktop"
     };
 
     const string[] DEFAULT_APP_AUDIO = {
-      "file:///usr/share/applications/org.gnome.Rhythmbox3.desktop",
-      "file:///usr/share/applications/rhythmbox.desktop",
-      "file:///usr/share/applications/spotify.desktop",
-      "file:///usr/share/applications/exaile.desktop",
-      "file:///usr/share/applications/songbird.desktop",
-      "file:///usr/share/applications/noise.desktop",
-      "file:///usr/share/applications/org.kde.elisa.desktop",
-      "file:///usr/share/applications/kde4/amarok.desktop"
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Rhythmbox3.desktop",
+      "file://%%LOCALBASE%%/share/applications/exaile.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.elisa.desktop",
     };
 
     const string[] DEFAULT_APP_VIDEO = {
-      "file:///usr/share/applications/vlc.desktop",
-      "file:///usr/share/applications/totem.desktop",
-      "file:///usr/share/applications/mpv.desktop",
-      "file:///usr/share/applications/mplayer.desktop",
-      "file:///usr/share/applications/audience.desktop",
-      "file:///usr/share/applications/org.xfce.Parole.desktop",
-      "file:///usr/share/applications/io.github.celluloid_player.Celluloid.desktop",
-      "file:///usr/share/applications/org.kde.dragonplayer.desktop"
+      "file://%%LOCALBASE%%/share/applications/vlc.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Totem.desktop",
+      "file://%%LOCALBASE%%/share/applications/mpv.desktop",
+      "file://%%LOCALBASE%%/share/applications/io.elementary.videos.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.xfce.Parole.desktop",
+      "file://%%LOCALBASE%%/share/applications/io.github.celluloid_player.Celluloid.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.dragonplayer.desktop"
     };
 
     const string[] DEFAULT_APP_PHOTO = {
-      "file:///usr/share/applications/pix.desktop",
-      "file:///usr/share/applications/gimp.desktop",
-      "file:///usr/share/applications/eog.desktop",
-      "file:///usr/share/applications/xviewer.desktop",
-      "file:///usr/share/applications/eom.desktop",
-      "file:///usr/share/applications/gnome-photos.desktop",
-      "file:///usr/share/applications/org.gnome.Photos.desktop",
-      "file:///usr/share/applications/shotwell.desktop",
-      "file:///usr/share/applications/org.gnome.Shotwell.desktop",
-      "file:///usr/share/applications/org.kde.gwenview.desktop",
-      "file:///usr/share/applications/kde4/digikam.desktop"
+      "file://%%LOCALBASE%%/share/applications/gimp.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.eog.desktop",
+      "file://%%LOCALBASE%%/share/applications/xviewer.desktop",
+      "file://%%LOCALBASE%%/share/applications/eom.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Photos.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Shotwell.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.gwenview.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.digikam.desktop"
     };
 
     const string[] DEFAULT_APP_MESSENGER = {
-      "file:///usr/share/applications/signal-desktop.desktop",
-      "file:///usr/share/applications/ferdium.desktop",
-      "file:///usr/share/applications/pidgin.desktop",
-      "file:///usr/share/applications/org.telegram.desktop.desktop",
-      "file:///usr/share/applications/empathy.desktop",
-      "file:///usr/share/applications/birdie.desktop",
-      "file:///usr/share/applications/kde4/kopete.desktop"
+      "file://%%LOCALBASE%%/share/applications/signal-desktop.desktop",
+      "file://%%LOCALBASE%%/share/applications/pidgin.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.telegram.desktop.desktop"
     };
 
     const string[] DEFAULT_APP_FILE_MANAGER = {
-      "file:///usr/share/applications/nemo.desktop",
-      "file:///usr/share/applications/thunar.desktop",
-      "file:///usr/share/applications/caja.desktop",
-      "file:///usr/share/applications/org.kde.dolphin.desktop",
-      "file:///usr/share/applications/dolphin.desktop",
-      "file:///usr/share/applications/org.gnome.Nautilus.desktop"
+      "file://%%LOCALBASE%%/share/applications/nemo.desktop",
+      "file://%%LOCALBASE%%/share/applications/thunar.desktop",
+      "file://%%LOCALBASE%%/share/applications/caja.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.kde.dolphin.desktop",
+      "file://%%LOCALBASE%%/share/applications/org.gnome.Nautilus.desktop"
     };
 
     /**
