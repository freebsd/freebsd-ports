--- src/backends/libinput/device.cpp.orig	2025-10-16 11:33:48 UTC
+++ src/backends/libinput/device.cpp
@@ -467,9 +467,11 @@ Device::Device(libinput_device *device, QObject *paren
     if (udevDevice != nullptr) {
         const auto devPath = udev_device_get_devpath(udevDevice);
 
-        // In UDev, all virtual uinput devices have a devpath start with /devices/virtual
-        m_isVirtual = strstr(devPath, "/devices/virtual/") != nullptr;
-        udev_device_unref(udevDevice);
+        if (devPath != nullptr) {
+            // In UDev, all virtual uinput devices have a devpath start with /devices/virtual
+            m_isVirtual = strstr(devPath, "/devices/virtual/") != nullptr;
+            udev_device_unref(udevDevice);
+        }
     }
 
     QDBusConnection::sessionBus().registerObject(QStringLiteral("/org/kde/KWin/InputDevice/") + m_sysName,
