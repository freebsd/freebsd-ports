Modify the default configuration to fit in to FreeBSD. That is replace '/usr/bin'
with '/usr/local/bin' and so on.
The setting of '$PATH' I find a bit dumb... this should respect the values of the
users profile...

--- src/common/Configuration.h.orig	2016-08-28 11:54:03 UTC
+++ src/common/Configuration.h
@@ -58,11 +58,11 @@ namespace SDDM {
 
         // TODO: Not absolutely sure if everything belongs here. Xsessions, VT and probably some more seem universal
         Section(X11,
-            Entry(ServerPath,          QString,     _S("/usr/bin/X"),                           _S("Path to X server binary"));
+            Entry(ServerPath,          QString,     _S("/usr/local/bin/X"),                           _S("Path to X server binary"));
             Entry(ServerArguments,     QString,     _S("-nolisten tcp"),                        _S("Arguments passed to the X server invocation"));
-            Entry(XephyrPath,          QString,     _S("/usr/bin/Xephyr"),                      _S("Path to Xephyr binary"));
-            Entry(XauthPath,           QString,     _S("/usr/bin/xauth"),                       _S("Path to xauth binary"));
-            Entry(SessionDir,          QString,     _S("/usr/share/xsessions"),                 _S("Directory containing available X sessions"));
+            Entry(XephyrPath,          QString,     _S("/usr/local/bin/Xephyr"),                      _S("Path to Xephyr binary"));
+            Entry(XauthPath,           QString,     _S("/usr/local/bin/xauth"),                       _S("Path to xauth binary"));
+            Entry(SessionDir,          QString,     _S("/usr/local/share/xsessions"),                 _S("Directory containing available X sessions"));
             Entry(SessionCommand,      QString,     _S(SESSION_COMMAND),                        _S("Path to a script to execute when starting the desktop session"));
 	    Entry(SessionLogFile,      QString,     _S(".local/share/sddm/xorg-session.log"),   _S("Path to the user session log file"));
 	    Entry(UserAuthFile,        QString,     _S(".Xauthority"),                          _S("Path to the Xauthority file"));
@@ -72,13 +72,13 @@ namespace SDDM {
         );
 
         Section(Wayland,
-            Entry(SessionDir,          QString,     _S("/usr/share/wayland-sessions"),          _S("Directory containing available Wayland sessions"));
+            Entry(SessionDir,          QString,     _S("/usr/local/share/wayland-sessions"),          _S("Directory containing available Wayland sessions"));
             Entry(SessionCommand,      QString,     _S(WAYLAND_SESSION_COMMAND),                _S("Path to a script to execute when starting the desktop session"));
 	    Entry(SessionLogFile,      QString,     _S(".local/share/sddm/wayland-session.log"),_S("Path to the user session log file"));
         );
 
         Section(Users,
-            Entry(DefaultPath,         QString,     _S("/bin:/usr/bin:/usr/local/bin"),         _S("Default $PATH for logged in users"));
+            Entry(DefaultPath,         QString,     _S("/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"),         _S("Default $PATH for logged in users"));
             Entry(MinimumUid,          int,         UID_MIN,                                    _S("Minimum user id for displayed users"));
             Entry(MaximumUid,          int,         UID_MAX,                                    _S("Maximum user id for displayed users"));
             Entry(HideUsers,           QStringList, QStringList(),                              _S("Comma-separated list of users that should not be listed"));
