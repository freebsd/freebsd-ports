$ kwin_wayland --xwayland
[...]
kwin_xwl: Failed to find free X11 connection socket
Failed to establish X11 socket

--- src/xwl/lib/xwaylandsocket.cpp.orig	2021-10-26 12:27:37 UTC
+++ src/xwl/lib/xwaylandsocket.cpp
@@ -183,10 +183,17 @@ XwaylandSocket::XwaylandSocket(OperationMode mode)
             continue;
         }
 
+#if defined(Q_OS_LINUX)
         const int abstractFileDescriptor = listen_helper(socketFilePath, UnixSocketAddress::Type::Abstract, mode);
+#else
+        const int abstractFileDescriptor = listen_helper(socketFilePath + "_", UnixSocketAddress::Type::Unix, mode);
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
@@ -212,6 +219,9 @@ XwaylandSocket::~XwaylandSocket()
     }
     if (!m_socketFilePath.isEmpty()) {
         QFile::remove(m_socketFilePath);
+#if !defined(Q_OS_LINUX)
+        QFile::remove(m_socketFilePath + "_");
+#endif
     }
     if (!m_lockFilePath.isEmpty()) {
         QFile::remove(m_lockFilePath);
