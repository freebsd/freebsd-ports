--- shell/plugins/panels/bluetooth/Panel.qml.orig
+++ shell/plugins/panels/bluetooth/Panel.qml
@@ -21,7 +21,10 @@
   // this map only keeps the panel responsive while BlueZ catches up.
   property var pendingActions: ({})
 
-  readonly property var adapter: Bluetooth.defaultAdapter
+  // FreeBSD has no BlueZ: FreeBSDBluetooth reads FreeBSD's own Bluetooth
+  // stack and stands in for Quickshell.Bluetooth with the same shape.
+  FreeBSDBluetooth { id: freebsdBluetooth; active: true; fast: root.opened }
+  readonly property var adapter: freebsdBluetooth.defaultAdapter
 
   // True while this instance owes BlueZ a StopDiscovery: set when it starts
   // discovery (or opens onto a session already running) and cleared once
@@ -29,7 +32,7 @@
   // Discovering property also reflects sessions other clients hold, which are
   // never this panel's to stop.
   property bool owesDiscoveryStop: false
-  readonly property var devices: Bluetooth.devices ? Bluetooth.devices.values : []
+  readonly property var devices: freebsdBluetooth.devices ? freebsdBluetooth.devices.values : []
   readonly property var pipewireNodes: Pipewire.nodes ? Pipewire.nodes.values : []
   property var pendingAudioOutputDevice: null
   property int pendingAudioOutputAttempts: 0
