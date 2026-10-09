--- shell/plugins/panels/network/FreeBSDWifi.qml.orig
+++ shell/plugins/panels/network/FreeBSDWifi.qml
@@ -0,0 +1,258 @@
+import QtQuick
+import Quickshell
+import Quickshell.Io
+import Quickshell.Networking
+
+// FreeBSD stand-in for the parts of Quickshell.Networking the network panel
+// uses. Quickshell's Networking only has a NetworkManager backend, which
+// FreeBSD lacks, so this drives wpa_supplicant through omarchy-wifi and
+// presents the same shape: devices with networks, each network with
+// connect/connectWithPsk/disconnect/forget and a connectionFailed signal.
+Item {
+  id: wifi
+
+  // Poll only when the panel uses this backend.
+  property bool active: false
+  // Poll briskly while the panel is open, and only to keep the bar icon
+  // current otherwise.
+  property bool fast: false
+
+  property var status: ({})
+  readonly property bool available: status.available === true
+  readonly property var devices: ({ values: deviceList })
+  property var deviceList: []
+
+  // The panel flips this to switch the radio; refresh() keeps it in step
+  // with the interface without calling back into the setter.
+  property bool wifiEnabled: false
+  property bool syncing: false
+  onWifiEnabledChanged: {
+    if (syncing) return
+    radioProc.command = ["omarchy-wifi", wifiEnabled ? "on" : "off"]
+    radioProc.running = true
+  }
+
+  readonly property bool canCheckConnectivity: false
+  readonly property bool connectivityCheckEnabled: false
+  readonly property int connectivity: NetworkConnectivity.Unknown
+  function checkConnectivity() {}
+
+  function securityType(name) {
+    switch (name) {
+      case "open": return WifiSecurityType.Open
+      case "owe": return WifiSecurityType.Owe
+      case "wep": return WifiSecurityType.StaticWep
+      case "wpa-psk": return WifiSecurityType.WpaPsk
+      case "wpa2-psk": return WifiSecurityType.Wpa2Psk
+      case "sae": return WifiSecurityType.Sae
+      case "wpa-eap": return WifiSecurityType.WpaEap
+      case "wpa2-eap": return WifiSecurityType.Wpa2Eap
+    }
+    return WifiSecurityType.Unknown
+  }
+
+  // One network object per SSID, kept across refreshes so the panel's
+  // Connections and networkForSsid() lookups stay bound to the same object.
+  property var networkObjects: ({})
+
+  Component {
+    id: networkComponent
+    QtObject {
+      property string name: ""
+      property bool connected: false
+      property bool known: false
+      property int security: WifiSecurityType.Unknown
+      property real signalStrength: 0
+      property bool stateChanging: false
+      signal connectionFailed(int reason)
+
+      function connect() { wifi.runAction(this, ["omarchy-wifi", "connect", name], "") }
+      function connectWithPsk(psk) { wifi.runAction(this, ["omarchy-wifi", "connect", name, "--psk"], psk) }
+      function disconnect() { wifi.runAction(this, ["omarchy-wifi", "disconnect"], "") }
+      function forget() { wifi.runAction(this, ["omarchy-wifi", "forget", name], "") }
+    }
+  }
+
+  Component {
+    id: wifiDeviceComponent
+    QtObject {
+      property string name: ""
+      readonly property int type: DeviceType.Wifi
+      property bool connected: false
+      property var networks: ({ values: [] })
+      property bool scannerEnabled: false
+      onScannerEnabledChanged: if (scannerEnabled) wifi.scan()
+    }
+  }
+
+  Component {
+    id: wiredDeviceComponent
+    QtObject {
+      property string name: ""
+      readonly property int type: DeviceType.Wired
+      property bool connected: false
+    }
+  }
+
+  property var wifiDevice: null
+  property var wiredDevices: ({})
+
+  function applyStatus(next) {
+    status = next
+    syncing = true
+    wifiEnabled = next.enabled === true
+    syncing = false
+
+    // Like NetworkManager, keep the Wi-Fi device while the radio is off: the
+    // panel's on/off switch hangs off it.
+    var list = []
+    if (next.available) {
+      if (!wifiDevice) wifiDevice = wifiDeviceComponent.createObject(wifi)
+      wifiDevice.name = next.iface || ""
+      wifiDevice.connected = next.connected === true
+      list.push(wifiDevice)
+    } else if (wifiDevice) {
+      wifiDevice.destroy()
+      wifiDevice = null
+    }
+
+    var wired = next.wired || []
+    var seen = {}
+    for (var i = 0; i < wired.length; i++) {
+      var w = wiredDevices[wired[i].name]
+      if (!w) {
+        w = wiredDeviceComponent.createObject(wifi, { name: wired[i].name })
+        wiredDevices[wired[i].name] = w
+      }
+      w.connected = wired[i].connected === true
+      seen[wired[i].name] = true
+      list.push(w)
+    }
+    for (var name in wiredDevices) {
+      if (!seen[name]) {
+        wiredDevices[name].destroy()
+        delete wiredDevices[name]
+      }
+    }
+    deviceList = list
+  }
+
+  function applyNetworks(rows) {
+    if (!wifiDevice) return
+    if (!wifiEnabled) rows = []
+    var seen = {}
+    var values = []
+    for (var i = 0; i < rows.length; i++) {
+      var row = rows[i]
+      var net = networkObjects[row.ssid]
+      if (!net) {
+        net = networkComponent.createObject(wifi, { name: row.ssid })
+        networkObjects[row.ssid] = net
+      }
+      net.security = securityType(row.security)
+      net.signalStrength = row.signal
+      net.known = row.known === true
+      if (!net.stateChanging) net.connected = row.connected === true
+      seen[row.ssid] = true
+      values.push(net)
+    }
+    for (var ssid in networkObjects) {
+      if (!seen[ssid] && !networkObjects[ssid].stateChanging) {
+        networkObjects[ssid].destroy()
+        delete networkObjects[ssid]
+      }
+    }
+    wifiDevice.networks = { values: values }
+  }
+
+  function refresh() {
+    if (!statusProc.running) statusProc.running = true
+    if (wifiDevice && wifiDevice.scannerEnabled && !networksProc.running) networksProc.running = true
+  }
+
+  function scan() {
+    if (!scanProc.running) scanProc.running = true
+  }
+
+  property var actionNetwork: null
+  property string actionSecret: ""
+
+  function runAction(network, command, secret) {
+    if (actionProc.running) return
+    actionNetwork = network
+    actionSecret = secret
+    network.stateChanging = true
+    actionProc.command = command
+    actionProc.running = true
+  }
+
+  Process {
+    id: statusProc
+    command: ["omarchy-wifi", "status"]
+    stdout: StdioCollector {
+      waitForEnd: true
+      onStreamFinished: {
+        try { wifi.applyStatus(JSON.parse(text)) } catch (e) {}
+      }
+    }
+  }
+
+  Process {
+    id: networksProc
+    command: ["omarchy-wifi", "networks"]
+    stdout: StdioCollector {
+      waitForEnd: true
+      onStreamFinished: {
+        try { wifi.applyNetworks(JSON.parse(text)) } catch (e) {}
+      }
+    }
+  }
+
+  Process { id: scanProc; command: ["omarchy-wifi", "scan"] }
+
+  Process {
+    id: radioProc
+    onExited: wifi.refresh()
+  }
+
+  // Exit codes from omarchy-wifi connect: 2 a rejected passphrase, 3 no
+  // association in time.
+  Process {
+    id: actionProc
+    stdinEnabled: true
+    onStarted: {
+      if (wifi.actionSecret !== "") write(wifi.actionSecret + "\n")
+      wifi.actionSecret = ""
+    }
+    onExited: function(exitCode) {
+      var net = wifi.actionNetwork
+      wifi.actionNetwork = null
+      if (!net) return
+      var connecting = command.length > 1 && command[1] === "connect"
+      if (connecting) net.connected = exitCode === 0
+      else if (command[1] === "disconnect" && exitCode === 0) net.connected = false
+      else if (command[1] === "forget" && exitCode === 0) net.known = false
+      net.stateChanging = false
+      if (connecting && exitCode !== 0) {
+        net.connectionFailed(exitCode === 2 ? ConnectionFailReason.WifiAuthTimeout : ConnectionFailReason.WifiClientFailed)
+      }
+      wifi.refresh()
+    }
+  }
+
+  Timer {
+    interval: wifi.fast ? 3000 : 20000
+    repeat: true
+    running: wifi.active
+    triggeredOnStart: true
+    onTriggered: wifi.refresh()
+  }
+
+  // Keep scanning while the panel is open, as NetworkManager's scanner does.
+  Timer {
+    interval: 10000
+    repeat: true
+    running: wifi.active && !!wifi.wifiDevice && wifi.wifiDevice.scannerEnabled
+    onTriggered: wifi.scan()
+  }
+}
