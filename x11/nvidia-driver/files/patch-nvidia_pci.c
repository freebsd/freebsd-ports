--- src/nvidia_pci.c.orig	Thu May 29 02:51:52 2003
+++ src/nvidia_pci.c	Fri Oct  3 01:19:55 2003
@@ -33,6 +33,18 @@
     if (vendor != NVIDIA_VENDORID || device < 0x0020)
         return ENXIO;
 
+    /* Exclude nForce MCP devices from detection */
+    if (device >= 0x01A4 && device <= 0x01ef)
+    	return ENXIO;
+    	
+    /* Exclude nForce2 MCP2 devices from detection */
+    if (device >= 0x0060 && device <= 0x006e)
+    	return ENXIO;
+
+    /* Exclude nForce3 MCP3 devices from detection */
+    if (device >= 0x00d4 && device <= 0x00da)
+    	return ENXIO;
+    
     if (rm_get_device_name(device, NV_DEVICE_NAME_LENGTH, name)
             != RM_OK) {
         strcpy(name, "Unknown");
