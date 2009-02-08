diff -u ../kinit/klauncher.cpp ../kinit/klauncher.cpp
--- ../kinit/klauncher.cpp	(revision 918403)
+++ ../kinit/klauncher.cpp	(revision 918654)
@@ -58,6 +58,9 @@
 
 // #define KLAUNCHER_VERBOSE_OUTPUT
 
+static const char* const s_DBusStartupTypeToString[] =
+    { "DBusNone", "DBusUnique", "DBusMulti", "DBusWait", "ERROR" };
+
 using namespace KIO;
 
 IdleSlave::IdleSlave(QObject *parent)
@@ -167,7 +170,7 @@
 
 KLauncher::KLauncher(int _kdeinitSocket)
   : QObject(0),
-    kdeinitSocket(_kdeinitSocket), dontBlockReading(false)
+    kdeinitSocket(_kdeinitSocket)
 {
 #ifdef Q_WS_X11
    mCached_dpy = NULL;
@@ -276,8 +279,24 @@
 {
   ssize_t result;
   int bytes_left = len;
-  while ( bytes_left > 0)
-  {
+    while (bytes_left > 0) {
+        // in case we get a request to start an application and data arrive
+        // to kdeinitSocket at the same time, requestStart() will already
+        // call slotKDEInitData(), so we must check there's still something
+        // to read, otherwise this would block
+
+        // Same thing if kdeinit dies without warning.
+
+        fd_set in;
+        timeval tm = { 30, 0 }; // 30 seconds timeout, so we're not stuck in case kdeinit dies on us
+        FD_ZERO ( &in );
+        FD_SET( sock, &in );
+        select( sock + 1, &in, 0, 0, &tm );
+        if( !FD_ISSET( sock, &in )) {
+            kDebug(7016) << "read_socket" << sock << "nothing to read, kdeinit4 must be dead";
+            return -1;
+        }
+
      result = read(sock, buffer, bytes_left);
      if (result > 0)
      {
@@ -298,21 +317,7 @@
 {
    klauncher_header request_header;
    QByteArray requestData;
-   if( dontBlockReading )
-   {
-   // in case we get a request to start an application and data arrive
-   // to kdeinitSocket at the same time, requestStart() will already
-   // call slotKDEInitData(), so we must check there's still something
-   // to read, otherwise this would block
-      fd_set in;
-      timeval tm = { 0, 0 };
-      FD_ZERO ( &in );
-      FD_SET( kdeinitSocket, &in );
-      select( kdeinitSocket + 1, &in, 0, 0, &tm );
-      if( !FD_ISSET( kdeinitSocket, &in ))
-         return;
-   }
-   dontBlockReading = false;
+
    int result = read_socket(kdeinitSocket, (char *) &request_header,
                             sizeof( request_header));
    if (result == -1)
@@ -391,15 +396,19 @@
       if (request->pid == pid)
       {
          if (request->dbus_startup_type == KService::DBusWait)
-            request->status = KLaunchRequest::Done;
+             request->status = KLaunchRequest::Done;
          else if ((request->dbus_startup_type == KService::DBusUnique)
-                  && QDBusConnection::sessionBus().interface()->isServiceRegistered(request->dbus_name))
-            request->status = KLaunchRequest::Running;
-         else
-            request->status = KLaunchRequest::Error;
+                  && QDBusConnection::sessionBus().interface()->isServiceRegistered(request->dbus_name)) {
+             request->status = KLaunchRequest::Running;
 #ifdef KLAUNCHER_VERBOSE_OUTPUT
-         kDebug(7016) << pid << "died, requestDone. status=" << request->status;
+             kDebug(7016) << pid << "running as a unique app";
 #endif
+         } else {
+             request->status = KLaunchRequest::Error;
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+             kDebug(7016) << pid << "died, requestDone. status=" << request->status;
+#endif
+         }
          requestDone(request);
          return;
       }
@@ -444,19 +453,29 @@
       if (request->status != KLaunchRequest::Launching)
          continue;
 
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+      kDebug(7016) << "had pending request" << request->name << s_DBusStartupTypeToString[request->dbus_startup_type] << "dbus_name" << request->dbus_name << request->tolerant_dbus_name;
+#endif
       // For unique services check the requested service name first
-      if ((request->dbus_startup_type == KService::DBusUnique) &&
-          ((appId == request->dbus_name) ||
-           QDBusConnection::sessionBus().interface()->isServiceRegistered(request->dbus_name)))
-      {
-         request->status = KLaunchRequest::Running;
-         requestDone(request);
-         continue;
+      if (request->dbus_startup_type == KService::DBusUnique) {
+          if ((appId == request->dbus_name) || // just started
+              QDBusConnection::sessionBus().interface()->isServiceRegistered(request->dbus_name)) { // was already running
+              request->status = KLaunchRequest::Running;
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+              kDebug(7016) << "OK, unique app" << request->dbus_name << "is running";
+#endif
+              requestDone(request);
+              continue;
+          } else {
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+              kDebug(7016) << "unique app" << request->dbus_name << "not running yet";
+#endif
+          }
       }
 
-      const QString rAppId = request->dbus_name;
+      const QString rAppId = !request->tolerant_dbus_name.isEmpty() ? request->tolerant_dbus_name : request->dbus_name;
 #ifdef KLAUNCHER_VERBOSE_OUTPUT
-      kDebug(7016) << "had pending request" << rAppId;
+      //kDebug(7016) << "using" << rAppId << "for matching";
 #endif
       if (rAppId.isEmpty())
           continue;
@@ -647,17 +666,21 @@
    request_header.cmd = LAUNCHER_EXEC_NEW;
 #endif
    request_header.arg_length = requestData.length();
+
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+   kDebug(7016) << "Asking kdeinit to start" << request->name << request->arg_list
+                << "cmd=" << commandToString(request_header.cmd);
+#endif
+
    write(kdeinitSocket, &request_header, sizeof(request_header));
    write(kdeinitSocket, requestData.data(), requestData.length());
 
    // Wait for pid to return.
    lastRequest = request;
-   dontBlockReading = false;
    do {
       slotKDEInitData( kdeinitSocket );
    }
    while (lastRequest != 0);
-   dontBlockReading = true;
 #endif
 }
 
@@ -812,11 +835,18 @@
                request->dbus_name = v.toString().toUtf8();
            }
            if (request->dbus_name.isEmpty()) {
-               request->dbus_name = "*." + QFile::encodeName(KRun::binaryName(service->exec(), true));
+               const QString binName = KRun::binaryName(service->exec(), true);
+               request->dbus_name = "org.kde." + binName;
+               request->tolerant_dbus_name = "*." + binName;
            }
        }
    }
 
+#ifdef KLAUNCHER_VERBOSE_OUTPUT
+   kDebug(7016) << "name=" << request->name << "dbus_name=" << request->dbus_name
+                << "startup type=" << s_DBusStartupTypeToString[request->dbus_startup_type];
+#endif
+
    request->pid = 0;
    request->envs = envs;
    send_service_startup_info( request, service, startup_id, envs );
@@ -932,7 +962,7 @@
        request->arg_list.append(arg.toLocal8Bit());
    }
 
-   request->name = app.toLocal8Bit();
+   request->name = app;
 
    if (wait)
       request->dbus_startup_type = KService::DBusWait;
@@ -1107,7 +1137,7 @@
     }
     if (mSlaveValgrind == arg1)
     {
-       arg_list.prepend(QFile::encodeName(KLibLoader::findLibrary(name.toLocal8Bit())));
+       arg_list.prepend(QFile::encodeName(KLibLoader::findLibrary(name)));
        arg_list.prepend(QFile::encodeName(KStandardDirs::locate("exe", "kioslave")));
        name = "valgrind";
        if (!mSlaveValgrindSkin.isEmpty()) {
