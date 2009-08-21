--- plasma/applets/system-monitor/net.cpp.orig	2009-08-21 01:22:09.000000000 +0200
+++ plasma/applets/system-monitor/net.cpp	2009-08-21 01:28:00.000000000 +0200
@@ -26,7 +26,7 @@
 
 SM::Net::Net(QObject *parent, const QVariantList &args)
     : SM::Applet(parent, args)
-    , m_rx("network/interfaces/(\\w+)/transmitter/data")
+    , m_rx("^network/interfaces/(\\w+)/transmitter/data$")
 {
     setHasConfigurationInterface(true);
     resize(234 + 20 + 23, 135 + 20 + 25);
@@ -58,7 +58,8 @@
     connect(engine(), SIGNAL(sourceRemoved(const QString&)),
             this, SLOT(sourceRemoved(const QString&)));
     if (!engine()->sources().isEmpty()) {
-        sourcesAdded();
+        foreach (const QString& source, engine()->sources())
+            sourceAdded(source);
     }
 }
 
