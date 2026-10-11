--- shell/plugins/panels/bluetooth/FreeBSDBluetooth.qml.orig
+++ shell/plugins/panels/bluetooth/FreeBSDBluetooth.qml
@@ -0,0 +1,131 @@
+import QtQuick
+import Quickshell
+import Quickshell.Io
+
+// FreeBSD stand-in for the parts of Quickshell.Bluetooth the Bluetooth panel
+// uses. Quickshell's Bluetooth module talks to BlueZ, which FreeBSD lacks, so
+// this reads FreeBSD's own stack through omarchy-bluetooth. The panel already
+// runs omarchy-bluetooth-device and omarchy-bluetooth-power for its actions;
+// this only supplies the adapter and device state, and discovery.
+Item {
+  id: bt
+
+  property bool active: false
+  // Poll briskly while the panel is open, and only to keep the bar icon
+  // current otherwise.
+  property bool fast: false
+
+  property var status: ({})
+  readonly property bool present: status.present === true
+  property var deviceList: []
+  readonly property var devices: ({ values: deviceList })
+  readonly property var defaultAdapter: present ? adapter : null
+
+  QtObject {
+    id: adapter
+    property bool enabled: bt.status.enabled === true
+    // The panel writes this to start and stop discovery; an inquiry runs for
+    // about ten seconds and then reports discovering false again.
+    property bool discovering: false
+    onDiscoveringChanged: {
+      if (discovering && !discoverProc.running) discoverProc.running = true
+    }
+  }
+
+  Component {
+    id: deviceComponent
+    QtObject {
+      property string address: ""
+      property string name: ""
+      readonly property string deviceName: name
+      readonly property string alias: name
+      property bool connected: false
+      property bool paired: false
+      readonly property bool bonded: paired
+      readonly property bool trusted: paired
+      function disconnect() {}
+    }
+  }
+
+  property var deviceObjects: ({})
+
+  function applyDevices(rows) {
+    var seen = {}
+    var values = []
+    for (var i = 0; i < rows.length; i++) {
+      var row = rows[i]
+      var d = deviceObjects[row.address]
+      if (!d) {
+        d = deviceComponent.createObject(bt, { address: row.address })
+        deviceObjects[row.address] = d
+      }
+      d.name = row.name || ""
+      d.connected = row.connected === true
+      d.paired = row.paired === true
+      seen[row.address] = true
+      values.push(d)
+    }
+    for (var address in deviceObjects) {
+      if (!seen[address]) {
+        deviceObjects[address].destroy()
+        delete deviceObjects[address]
+      }
+    }
+    deviceList = values
+  }
+
+  function refresh() {
+    if (!statusProc.running) statusProc.running = true
+    if (!devicesProc.running) devicesProc.running = true
+  }
+
+  Process {
+    id: statusProc
+    command: ["omarchy-bluetooth", "status"]
+    stdout: StdioCollector {
+      waitForEnd: true
+      onStreamFinished: {
+        try { bt.status = JSON.parse(text) } catch (e) {}
+      }
+    }
+  }
+
+  Process {
+    id: devicesProc
+    command: ["omarchy-bluetooth", "devices"]
+    stdout: StdioCollector {
+      waitForEnd: true
+      onStreamFinished: {
+        try { bt.applyDevices(JSON.parse(text)) } catch (e) {}
+      }
+    }
+  }
+
+  // The panel's commands record their result as root; pick it up once at
+  // startup too, since nothing has run as root yet in a new session.
+  Process {
+    id: rootRefresh
+    command: ["omarchy-bluetooth", "refresh"]
+    onExited: bt.refresh()
+  }
+
+  Process {
+    id: discoverProc
+    command: ["omarchy-bluetooth", "discover"]
+    onExited: {
+      adapter.discovering = false
+      bt.refresh()
+    }
+  }
+
+  Component.onCompleted: if (active) rootRefresh.running = true
+  onActiveChanged: if (active) rootRefresh.running = true
+
+  Timer {
+    interval: bt.fast ? 3000 : 20000
+    repeat: true
+    running: bt.active
+    triggeredOnStart: true
+    onTriggered: bt.refresh()
+  }
+}
