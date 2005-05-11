--- src/nvidia_pci.c.orig	Mon Aug 16 17:40:56 2004
+++ src/nvidia_pci.c	Mon Aug 16 17:41:20 2004
@@ -218,6 +218,9 @@
 };
 
 DRIVER_MODULE(nvidia, pci, nvidia_pci_driver, nvidia_devclass, nvidia_modevent, 0);
+#if __FreeBSD_version > 502126
+MODULE_DEPEND(nvidia, mem, 1, 1, 1);
+#endif
 
 #ifdef NV_SUPPORT_OS_AGP
 MODULE_DEPEND(nvidia, agp, 1, 1, 1);
