$ kwin_wayland --xwayland
[...]
kwin_xwl: Failed to find free X11 connection socket
Failed to establish X11 socket

--- src/xwl/xwaylandsocket.cpp.orig	2021-08-31 11:41:03 UTC
+++ src/xwl/xwaylandsocket.cpp
@@ -179,10 +179,17 @@ XwaylandSocket::XwaylandSocket()
             continue;
         }
 
+#if defined(Q_OS_LINUX)
         const int abstractFileDescriptor = listen_helper(socketFilePath, UnixSocketAddress::Type::Abstract);
+#else
+        const int abstractFileDescriptor = listen_helper(socketFilePath + "_", UnixSocketAddress::Type::Unix);
+#endif
         if (abstractFileDescriptor == -1) {
             QFile::remove(lockFilePath);
             QFile::remove(socketFilePath);
+#if !defined(Q_OS_LINUX)
+            QFile::remove(socketFilePath + "_");
+#endif
             close(unixFileDescriptor);
             continue;
         }
@@ -208,6 +215,9 @@ XwaylandSocket::~XwaylandSocket()
     }
     if (!m_socketFilePath.isEmpty()) {
         QFile::remove(m_socketFilePath);
+#if !defined(Q_OS_LINUX)
+        QFile::remove(m_socketFilePath + "_");
+#endif
     }
     if (!m_lockFilePath.isEmpty()) {
         QFile::remove(m_lockFilePath);
