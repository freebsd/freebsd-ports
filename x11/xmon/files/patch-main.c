
>Submitter-Id:	current-users
>Originator:	Volker Stolz
>Organization:	Lehrstuhl für Informatik II
>Confidential:	no 
>Synopsis:	[patch] x11/xmon: Fix build on -CURRENT
>Severity:	non-critical
>Priority:	low
>Category:	ports
>Class:		sw-bug
>Release:	FreeBSD 4.9-RC i386
>Environment:
System: FreeBSD menelaos.informatik.rwth-aachen.de 4.9-RC FreeBSD 4.9-RC #10: Tue Oct 7 12:32:25 CEST 2003 root@menelaos.informatik.rwth-aachen.de:/usr/obj/usr/src/sys/MENELAOS i386


>Description:
Fix conflicting prototypes on -CURRENT.

Noten by: bento
Tested on: -CURRENT, -STABLE
>How-To-Repeat:
http://bento.freebsd.org/errorlogs/i386-5-latest/xmon-1.5.6.log
>Fix:
Add new patch-file files/patch-main.c:

--- patch-main.c begins here ---
--- main.c.orig	Tue Nov 25 14:05:21 2003
+++ main.c	Tue Nov 25 14:06:05 2003
@@ -36,6 +36,9 @@
 #include <fcntl.h>
 #endif
 
+#include <stdlib.h>
+#include <unistd.h>
+
 #include "xmond.h"
 #include "select_args.h"
 #include "commands.h"
@@ -74,9 +77,6 @@
 #if (mskcnt>4)
 static Bool ANYSET P((long *src));
 #endif
-
-extern char *getenv();
-extern int gethostname P((char *name, int namelen ));
 
 /* end function prototypes */
 
--- patch-main.c ends here ---

