--- kwin/client.h.orig	Sun Oct  6 16:00:30 2002
+++ kwin/client.h	Sun Oct  6 14:49:21 2002
@@ -161,6 +161,7 @@
     bool isTool() const; // KDE4 remove me
     bool isToolbar() const;
     bool isTopMenu() const;
+    bool isMenu() const; // compat. for KDE 3.0.x <alane@freebsd.org>
     bool isNormalWindow() const; // normal as in 'NET::Normal or NET::Unknown non-transient'
     bool isDialog() const;
 
@@ -505,6 +506,16 @@
 {
     return cmap;
 }
+
+/*
+  compat. for 3.0.x <alane@freebsd.org>
+*/
+
+inline bool Client::isMenu() const
+{
+  return isTopMenu();
+}
+
 
 class NoBorderClient : public Client
 {
