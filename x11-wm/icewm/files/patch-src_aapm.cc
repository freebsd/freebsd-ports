--- src/aapm.cc.orig	2006/12/24 15:56:15	1.18.2.3
+++ src/aapm.cc	2007/04/22 16:38:49	1.18.2.4
@@ -632,7 +632,7 @@
 
     //estimate applet's size
     for (i = 0; i < batteryNum; i++) {
-        if (acpiBatteries[i]->present == BAT_ABSENT)
+        if (mode == ACPI && acpiBatteries[i]->present == BAT_ABSENT)
             continue;
         if (taskBarShowApmTime)
             strcat(buf, "0:00");
