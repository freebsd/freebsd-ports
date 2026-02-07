--- js/misc/loginManager.js.orig	2025-04-13 15:04:25 UTC
+++ js/misc/loginManager.js
@@ -13,6 +13,12 @@ const SystemdLoginUser = Gio.DBusProxy.makeProxyWrappe
 const SystemdLoginSession = Gio.DBusProxy.makeProxyWrapper(SystemdLoginSessionIface);
 const SystemdLoginUser = Gio.DBusProxy.makeProxyWrapper(SystemdLoginUserIface);
 
+const ConsoleKitManagerIface = loadInterfaceXML('org.freedesktop.ConsoleKit.Manager');
+const ConsoleKitSessionIface = loadInterfaceXML('org.freedesktop.ConsoleKit.Session');
+const ConsoleKitManager = Gio.DBusProxy.makeProxyWrapper(ConsoleKitManagerIface);
+const ConsoleKitSession = Gio.DBusProxy.makeProxyWrapper(ConsoleKitSessionIface);
+
+
 function haveSystemd() {
     return GLib.access('/run/systemd/seats', 0) >= 0;
 }
@@ -46,7 +52,7 @@ export function canLock() {
             -1, null);
 
         let version = result.deepUnpack()[0].deepUnpack();
-        return haveSystemd() && versionCompare('3.5.91', version);
+        return versionCompare('3.5.91', version);
     } catch {
         return false;
     }
@@ -82,12 +88,84 @@ export function getLoginManager() {
         if (haveSystemd())
             _loginManager = new LoginManagerSystemd();
         else
-            _loginManager = new LoginManagerDummy();
+            _loginManager = new LoginManagerConsoleKit();
     }
 
     return _loginManager;
 }
 
+class LoginManagerConsoleKit extends Signals.EventEmitter {
+    constructor() {
+        super();
+
+        this._proxy = new ConsoleKitManager(Gio.DBus.system,
+            'org.freedesktop.ConsoleKit',
+            '/org/freedesktop/ConsoleKit/Manager');
+        this._proxy.connectSignal('PrepareForSleep',
+            this._prepareForSleep.bind(this));
+    }
+
+    async getCurrentSessionProxy() {
+        if (this._currentSession)
+            return this._currentSession;
+
+        try {
+            const [objectPath] = await this._proxy.GetCurrentSessionAsync();
+            this._currentSession = new ConsoleKitSession(Gio.DBus.system,
+                'org.freedesktop.ConsoleKit', objectPath);
+            return this._currentSession;
+        } catch (error) {
+            logError(error, 'Could not get a proxy for the current session');
+            return null;
+        }
+    }
+
+    async canSuspend() {
+        let canSuspend, needsAuth;
+
+        try {
+            const [result] = await this._proxy.CanSuspendAsync();
+            needsAuth = result === 'challenge';
+            canSuspend = needsAuth || result === 'yes';
+        } catch {
+            canSuspend = false;
+            needsAuth = false;
+        }
+        return {canSuspend, needsAuth};
+    }
+
+    async listSessions() {
+        try {
+            const [sessions] = await this._proxy.ListSessionsAsync();
+            return sessions;
+        } catch {
+            return [];
+        }
+    }
+
+    getSession(objectPath) {
+        return new ConsoleKitSession(Gio.DBus.system, 'org.freedesktop.ConsoleKit', objectPath);
+    }
+
+    suspend() {
+        this._proxy.SuspendAsync(true);
+    }
+
+    async inhibit(reason, cancellable) {
+        const inVariant = new GLib.Variant('(ssss)',
+            ['sleep', 'GNOME Shell', reason, 'delay']);
+        const [outVariant_, fdList] =
+            await this._proxy.call_with_unix_fd_list('Inhibit',
+                inVariant, 0, -1, null, cancellable);
+        const [fd] = fdList.steal_fds();
+        return new GioUnix.InputStream({fd});
+    }
+
+    _prepareForSleep(proxy, sender, [aboutToSuspend]) {
+        this.emit('prepare-for-sleep', aboutToSuspend);
+    }
+}
+
 class LoginManagerSystemd extends Signals.EventEmitter {
     constructor() {
         super();
@@ -230,16 +308,6 @@ class LoginManagerDummy extends Signals.EventEmitter  
             canSuspend: false,
             needsAuth: false,
         }));
-    }
-
-    canRebootToBootLoaderMenu() {
-        return new Promise(resolve => resolve({
-            canRebootToBootLoaderMenu: false,
-            needsAuth: false,
-        }));
-    }
-
-    setRebootToBootLoaderMenu() {
     }
 
     listSessions() {
