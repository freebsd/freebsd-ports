--- kcontrol/usbview/usbdevices.cpp.orig	Thu May  5 17:21:17 2005
+++ kcontrol/usbview/usbdevices.cpp	Thu May  5 17:43:04 2005
@@ -26,6 +26,7 @@
 
 #ifdef Q_OS_FREEBSD
 #include <sys/ioctl.h>
+#include <sys/param.h>
 #endif
 
 QPtrList<USBDevice> USBDevice::_devices;
@@ -260,11 +261,15 @@
 	_channels     = di.udi_nports;
 	
 	// determine the speed
+#if __FreeBSD_version > 490102
 	switch (di.udi_speed) {
 		case USB_SPEED_LOW:  _speed = 1.5;   break;
 		case USB_SPEED_FULL: _speed = 12.0;  break;
 		case USB_SPEED_HIGH: _speed = 480.0; break;
 	}
+#else
+	_speed = di.udi_lowspeed ? 1.5 : 12.0;
+#endif
 
 	// Get all attached devicenodes
 	for ( int i = 0; i < USB_MAX_DEVNAMES; ++i )
