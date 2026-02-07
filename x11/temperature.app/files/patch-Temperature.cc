--- Temperature.cc.orig	2010-02-07 06:43:52 UTC
+++ Temperature.cc
@@ -22,22 +22,27 @@
 #include <X11/Xlib.h>
 #include <iostream>
 #include <fstream>
-#include <stdlib.h>
-#include <stdio.h>
-#include <string.h>
+#include <cstdlib>
+#include <cstdio>
+#include <cstring>
 #include <unistd.h>
-#include <signal.h>
-#include <errno.h>
+#include <csignal>
+#include <cerrno>
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <math.h>
-#include <time.h>
+#include <cmath>
+#include <ctime>
 #include "Xpm.h"
 #include "Temperature.h"
 
 #include "pixmaps/main.xpm"
 #include "pixmaps/redlight.xpm"
 
+using std::cerr;
+using std::cout;
+using std::endl;
+using std::fstream;
+
 volatile static ChildStatus childStatus;
 
 static void catchBrokenPipe(int sig) 
@@ -415,7 +420,7 @@ void Temperature::run() 
             const char* verbose = (mVerbose ? "--verbose" : "--quiet");
             char* URL = new char[strlen(METAR_URL) + strlen(mStationId) + 1];
             sprintf(URL, METAR_URL, mStationId);
-            execlp("wget", "wget", "--cache=off", "--tries=0", verbose, "-O", tmpFile, URL, 0);
+            execlp("wget", "wget", "--no-cache", "--tries=0", verbose, "-O", tmpFile, URL, NULL);
             std::cerr << APPNAME << ": could not fetch temperature (wget not found in $PATH)" << std::endl;
             remove(tmpFile);
             exit(0);
