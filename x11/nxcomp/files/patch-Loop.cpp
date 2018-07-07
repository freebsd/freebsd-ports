Loop.cpp:6751:61: error: invalid operands to binary expression ('__bind<int &, sockaddr *, unsigned long>' and 'int')
  if (bind(proxyFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~
            /usr/include/c++/v1/system_error:577:1: note: candidate function not viable: no known conversion from '__bind<int &, sockaddr *, unsigned long>' to 'const std::__1::error_code' for 1st argument
            operator==(const error_code& __x, const error_code& __y) _NOEXCEPT
            ^

--- Loop.cpp.orig	2018-07-07 17:44:11 UTC
+++ Loop.cpp
@@ -3969,7 +3969,7 @@ int SetupTcpSocket()
     tcpAddr.sin_addr.s_addr = htonl(INADDR_ANY);
   }
 
-  if (bind(tcpFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
+  if (::bind(tcpFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
   {
     #ifdef PANIC
     *logofs << "Loop: PANIC! Call to bind failed for TCP port "
@@ -4055,7 +4055,7 @@ int SetupUnixSocket()
 
   *(unixAddr.sun_path + 107) = '\0';
 
-  if (bind(unixFD, (sockaddr *) &unixAddr, sizeof(unixAddr)) == -1)
+  if (::bind(unixFD, (sockaddr *) &unixAddr, sizeof(unixAddr)) == -1)
   {
     #ifdef PANIC
     *logofs << "Loop: PANIC! Call to bind failed for UNIX domain socket "
@@ -4567,7 +4567,7 @@ int ListenConnection(int port, const char *label)
     tcpAddr.sin_addr.s_addr = htonl(INADDR_ANY);
   }
 
-  if (bind(newFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
+  if (::bind(newFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
   {
     #ifdef PANIC
     *logofs << "Loop: PANIC! Call to bind failed for " << label
@@ -6748,7 +6748,7 @@ int WaitForRemote(int portNum)
 
   #endif
 
-  if (bind(proxyFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
+  if (::bind(proxyFD, (sockaddr *) &tcpAddr, sizeof(tcpAddr)) == -1)
   {
     #ifdef PANIC
     *logofs << "Loop: PANIC! Call to bind failed for TCP port "
