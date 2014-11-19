--- js/misc/loginManager.js.orig	2014-10-13 22:57:05.000000000 +0200
+++ js/misc/loginManager.js	2014-10-23 19:53:12.854065483 +0200
@@ -46,6 +46,32 @@
 const SystemdLoginManager = Gio.DBusProxy.makeProxyWrapper(SystemdLoginManagerIface);
 const SystemdLoginSession = Gio.DBusProxy.makeProxyWrapper(SystemdLoginSessionIface);
 
+const ConsoleKitManagerIface = '<node> \
+<interface name="org.freedesktop.ConsoleKit.Manager"> \
+<method name="CanRestart"> \
+    <arg type="b" direction="out"/> \
+</method> \
+<method name="CanStop"> \
+    <arg type="b" direction="out"/> \
+</method> \
+<method name="Restart" /> \
+<method name="Stop" /> \
+<method name="GetCurrentSession"> \
+    <arg type="o" direction="out" /> \
+</method> \
+</interface> \
+</node>';
+
+const ConsoleKitSessionIface = '<node> \
+<interface name="org.freedesktop.ConsoleKit.Session"> \
+<signal name="Lock" /> \
+<signal name="Unlock" /> \
+</interface> \
+</node>';
+
+const ConsoleKitSession = Gio.DBusProxy.makeProxyWrapper(ConsoleKitSessionIface);
+const ConsoleKitManager = Gio.DBusProxy.makeProxyWrapper(ConsoleKitManagerIface);
+
 function haveSystemd() {
     return GLib.access("/run/systemd/seats", 0) >= 0;
 }
@@ -75,7 +101,7 @@
                                                -1, null);
 
         let version = result.deep_unpack()[0].deep_unpack();
-        return haveSystemd() && versionCompare('3.5.91', version);
+        return versionCompare('3.5.91', version);
     } catch(e) {
         return false;
     }
@@ -93,7 +119,7 @@
         if (haveSystemd())
             _loginManager = new LoginManagerSystemd();
         else
-            _loginManager = new LoginManagerDummy();
+            _loginManager = new LoginManagerConsoleKit();
     }
 
     return _loginManager;
@@ -110,6 +136,9 @@
                                   Lang.bind(this, this._prepareForSleep));
     },
 
+    // Having this function is a bit of a hack since the Systemd and ConsoleKit
+    // session objects have different interfaces - but in both cases there are
+    // Lock/Unlock signals, and that's all we count upon at the moment.
     getCurrentSessionProxy: function(callback) {
         if (this._currentSession) {
             callback (this._currentSession);
@@ -177,13 +206,35 @@
 });
 Signals.addSignalMethods(LoginManagerSystemd.prototype);
 
-const LoginManagerDummy = new Lang.Class({
-    Name: 'LoginManagerDummy',
+const LoginManagerConsoleKit = new Lang.Class({
+    Name: 'LoginManagerConsoleKit',
+
+    _init: function() {
+        this._proxy = new ConsoleKitManager(Gio.DBus.system,
+                                            'org.freedesktop.ConsoleKit',
+                                            '/org/freedesktop/ConsoleKit/Manager');
+    },
 
+    // Having this function is a bit of a hack since the Systemd and ConsoleKit
+    // session objects have different interfaces - but in both cases there are
+    // Lock/Unlock signals, and that's all we count upon at the moment.
     getCurrentSessionProxy: function(callback) {
-        // we could return a DummySession object that fakes whatever callers
-        // expect (at the time of writing: connect() and connectSignal()
-        // methods), but just never calling the callback should be safer
+        if (this._currentSession) {
+            callback (this._currentSession);
+            return;
+        }
+
+        this._proxy.GetCurrentSessionRemote(Lang.bind(this,
+            function(result, error) {
+                if (error) {
+                    logError(error, 'Could not get a proxy for the current session');
+                } else {
+                    this._currentSession = new ConsoleKitSession(Gio.DBus.system,
+                                                                 'org.freedesktop.ConsoleKit',
+                                                                 result[0]);
+                    callback(this._currentSession);
+                }
+            }));
     },
 
     canSuspend: function(asyncCallback) {
@@ -203,4 +254,4 @@
         callback(null);
     }
 });
-Signals.addSignalMethods(LoginManagerDummy.prototype);
+Signals.addSignalMethods(LoginManagerConsoleKit.prototype);
