--- ./kdm/kfrontend/genkdmconf.c.orig	Thu Mar 21 21:11:30 2002
+++ ./kdm/kfrontend/genkdmconf.c	Thu Apr 18 21:22:40 2002
@@ -37,6 +37,10 @@
 #include <ctype.h>
 #include <stdarg.h>
 #include <fcntl.h>
+#include <sys/param.h>
+#ifdef BSD
+# include <utmp.h>
+#endif
 
 #if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
 # define ATTR_UNUSED __attribute__((unused))
@@ -358,11 +362,11 @@
 
 const char def_willing[] = 
 "#! /bin/sh\n"
-"# The output of this script is displayed in the chooser window.\n"
-"# (instead of \"Willing to manage\")\n"
+"# The output of this script is displayed in the chooser window\n"
+"# (instead of \"Willing to manage\").\n"
 "\n"
-"load=\"`uptime|sed -e 's/^.*load[^0-9]*//'`\"\n"
-"nrusers=\"`who|cut -c 1-8|sort -u|wc -l|sed 's/^[        ]*//'`\"\n"
+"load=`uptime|sed -e 's/^.*load[^0-9]*//'`\n"
+"nrusers=`who|cut -c 1-8|sort -u|wc -l|sed 's/^[        ]*//'`\n"
 "s=\"\"; [ \"$nrusers\" != 1 ] && s=s\n"
 "\n"
 "echo \"${nrusers} user${s}, load: ${load}\"\n";
@@ -377,7 +381,10 @@
 "  echo $! >$PIDFILE\n"
 "  wait $!\n"
 "  rm $PIDFILE\n"
-") &\n";
+") &\n"
+"\n"
+"#xconsole -geometry 480x130-0-0 -notify -verbose -fn fixed -exitOnFail -file /dev/xconsole &\n"
+"\n";
 
 const char def_startup[] = 
 "#! /bin/sh\n"
@@ -391,14 +398,11 @@
 "# By convention, both xconsole and xterm -C check that the\n"
 "# console is owned by the invoking user and is readable before attaching\n"
 "# the console output.  This way a random user can invoke xterm -C without\n"
-"# causing serious grief.\n"
-"# This is not required if you use PAM, as pam_console should handle it.\n"
+"# causing serious grief; still, it can cause havoc, so xconsole is started\n"
+"# by Xsetup usually.\n"
+"# This is not required if you use PAM with the pam_console module.\n"
 "#\n"
-#ifdef HAVE_PAM
 "#chown $USER /dev/console\n"
-#else
-"chown $USER /dev/console\n"
-#endif
 "\n"
 #ifdef _AIX
 "# We create a pseudodevice for finger.  (host:0 becomes kdm/host_0)\n"
@@ -425,11 +429,11 @@
 "  fi\n"
 "fi\n";
 #else
-"#exec sessreg -a -l $DISPLAY "
+"exec sessreg -a -l $DISPLAY"
 # ifdef BSD
-"-x " KDMCONF "/Xservers "
+" -x " KDMCONF "/Xservers -u " _PATH_UTMP
 # endif
-"$USER\n";
+" $USER\n";
 #endif /* _AIX */
 
 const char def_reset[] = 
@@ -437,16 +441,10 @@
 "# Xreset - run as root after session exits\n"
 "\n"
 "# Reassign ownership of the console to root, this should disallow\n"
-"# assignment of console output to any random users's xterm\n"
-"# This is not required if you use PAM, as pam_console should handle it.\n"
+"# assignment of console output to any random users's xterm. See Xstartup.\n"
 "#\n"
-#ifdef HAVE_PAM
 "#chown root /dev/console\n"
 "#chmod 622 /dev/console\n"
-#else
-"chown root /dev/console\n"
-"chmod 622 /dev/console\n"
-#endif
 "\n"
 #ifdef _AIX
 "if [ -f /usr/lib/X11/xdm/sessreg ]; then\n"
@@ -454,11 +452,11 @@
 "  exec /usr/lib/X11/xdm/sessreg -d -l xdm/$devname $USER\n"
 "fi\n";
 #else
-"#exec sessreg -d -l $DISPLAY "
+"exec sessreg -d -l $DISPLAY"
 # ifdef BSD
-"-x " KDMCONF "/Xservers "
+" -x " KDMCONF "/Xservers -u " _PATH_UTMP
 # endif
-"$USER\n";
+" $USER\n";
 #endif /* _AIX */
 
 const char def_session[] = 
