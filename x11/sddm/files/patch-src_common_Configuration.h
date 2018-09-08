Leave InputMethod empty by default since qtvirtualkeyboard does not appear to
be supported by the included themes.  The keyboard is drawn on top of the
login screen and has to be clicked away (button lower-right).

Set the default theme and cursor theme to breeze, because sddm is most likely
used together with Plasma.  If they aren't available sddm falls back to a
compiled-in theme.

--- src/common/Configuration.h.orig	2017-12-05 16:00:16 UTC
+++ src/common/Configuration.h
@@ -42,14 +42,14 @@ namespace SDDM {
         Entry(Numlock,             NumState,    NUM_NONE,                                       _S("Initial NumLock state. Can be on, off or none.\n"
                                                                                                    "If property is set to none, numlock won't be changed\n"
                                                                                                    "NOTE: Currently ignored if autologin is enabled."));
-        Entry(InputMethod,         QString,     QStringLiteral("qtvirtualkeyboard"),                   _S("Input method module"));
+        Entry(InputMethod,         QString,     QString(),                                      _S("Input method module"));
         //  Name   Entries (but it's a regular class again)
         Section(Theme,
             Entry(ThemeDir,            QString,     _S(DATA_INSTALL_DIR "/themes"),             _S("Theme directory path"));
-            Entry(Current,             QString,     _S(""),                                     _S("Current theme name"));
+            Entry(Current,             QString,     _S("breeze"),                               _S("Current theme name"));
             Entry(FacesDir,            QString,     _S(DATA_INSTALL_DIR "/faces"),              _S("Global directory for user avatars\n"
                                                                                                    "The files should be named <username>.face.icon"));
-            Entry(CursorTheme,         QString,     QString(),                                  _S("Cursor theme used in the greeter"));
+            Entry(CursorTheme,         QString,     _S("breeze_cursors"),                       _S("Cursor theme used in the greeter"));
             Entry(EnableAvatars,       bool,        true,                                       _S("Enable display of custom user avatars"));
             Entry(DisableAvatarsThreshold,int,      7,                                          _S("Number of users to use as threshold\n"
                                                                                                    "above which avatars are disabled\n"
@@ -80,7 +80,7 @@ namespace SDDM {
         );
 
         Section(Users,
-            Entry(DefaultPath,         QString,     _S("/usr/local/bin:/usr/bin:/bin"),         _S("Default $PATH for logged in users"));
+            Entry(DefaultPath,         QString,     _S("/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"),         _S("Default $PATH for logged in users"));
             Entry(MinimumUid,          int,         UID_MIN,                                    _S("Minimum user id for displayed users"));
             Entry(MaximumUid,          int,         UID_MAX,                                    _S("Maximum user id for displayed users"));
             Entry(HideUsers,           QStringList, QStringList(),                              _S("Comma-separated list of users that should not be listed"));
