--- ./solid/solid/managerbase.cpp.orig	2012-04-17 23:58:05.745260976 +0200
+++ ./solid/solid/managerbase.cpp	2012-04-18 00:00:48.605183174 +0200
@@ -90,7 +90,11 @@
 #        endif
 
 #        if defined (HUPNP_FOUND)
-            m_backends << new Solid::Backends::UPnP::UPnPDeviceManager(0);
+            bool solidUPnPEnabled
+                = QString::fromLocal8Bit(qgetenv("SOLID_UPNP")).toInt()==1;
+            if (solidUPnPEnabled) {
+                m_backends << new Solid::Backends::UPnP::UPnPDeviceManager(0);
+            }
 #        endif
     }
 }
