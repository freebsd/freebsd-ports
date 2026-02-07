--- js/gdm/loginDialog.js.orig	2025-04-13 15:04:25 UTC
+++ js/gdm/loginDialog.js
@@ -46,6 +46,10 @@ const _CONFLICTING_SESSION_DIALOG_TIMEOUT = 60;
 const _TIMED_LOGIN_IDLE_THRESHOLD = 5.0;
 const _CONFLICTING_SESSION_DIALOG_TIMEOUT = 60;
 
+function haveSystemd() {
+    return GLib.access('/run/systemd/seats', 0) >= 0;
+}
+
 export const UserListItem = GObject.registerClass({
     Signals: {'activate': {}},
 }, class UserListItem extends St.Button {
@@ -1142,6 +1146,7 @@ export const LoginDialog = GObject.registerClass({
     }
 
     async _findConflictingSession(startingSessionId) {
+        if (haveSystemd()) {
         const loginManager = LoginManager.getLoginManager();
         const sessions = await loginManager.listSessions();
         const [, , startingSessionOwner, ,] = sessions.find(([id, , , ,]) => id === startingSessionId);
@@ -1161,6 +1166,7 @@ export const LoginDialog = GObject.registerClass({
                 continue;
 
             return sessionProxy;
+        }
         }
 
         return null;
