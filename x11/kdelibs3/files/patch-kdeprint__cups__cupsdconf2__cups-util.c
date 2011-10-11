--- kdeprint/cups/cupsdconf2/cups-util.c.orig	2007-10-08 05:52:10.000000000 -0400
+++ kdeprint/cups/cupsdconf2/cups-util.c	2011-10-09 18:03:23.000000000 -0400
@@ -2,6 +2,7 @@
 #include <cups/http.h>
 #include <cups/cups.h>
 #include <stdlib.h>
+#include <stdio.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <unistd.h>
