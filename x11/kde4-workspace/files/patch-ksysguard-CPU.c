Index: ksysguard/ksysguardd/FreeBSD/CPU.c
===================================================================
RCS file: /home/kde/kdebase/ksysguard/ksysguardd/FreeBSD/CPU.c,v
retrieving revision 1.9
diff -u -5 -p -d -r1.9 CPU.c
--- ksysguard/ksysguardd/FreeBSD/CPU.c	17 Oct 2002 10:04:02 -0000	1.9
+++ ksysguard/ksysguardd/FreeBSD/CPU.c	3 Mar 2003 07:11:28 -0000
@@ -19,11 +19,16 @@
 
 	$Id: CPU.c,v 1.9 2002/10/17 10:04:02 garbanzo Exp $
 */
 
 #include <sys/types.h>
+#include <sys/param.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#else
+#include <sys/resource.h>
+#endif
 #include <sys/sysctl.h>
 
 #include <devstat.h>
 #include <fcntl.h>
 #include <nlist.h>
