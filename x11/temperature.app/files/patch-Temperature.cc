--- Temperature.cc.bak	2002-04-06 08:44:09.000000000 +0900
+++ Temperature.cc	2013-12-07 17:25:30.000000000 +0900
@@ -20,24 +20,29 @@
 //
 
 #include <X11/Xlib.h>
-#include <iostream.h>
-#include <fstream.h>
-#include <stdlib.h>
-#include <stdio.h>
-#include <string.h>
+#include <iostream>
+#include <fstream>
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
