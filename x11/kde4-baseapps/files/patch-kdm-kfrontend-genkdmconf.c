--- kdm/kfrontend/genkdmconf.c.orig	Wed May  8 14:21:31 2002
+++ kdm/kfrontend/genkdmconf.c	Sat May 25 13:19:06 2002
@@ -402,7 +402,7 @@
 "# by Xsetup usually.\n"
 "# This is not required if you use PAM with the pam_console module.\n"
 "#\n"
-"#chown $USER /dev/console\n"
+"chown $USER /dev/console\n"
 "\n"
 #ifdef _AIX
 "# We create a pseudodevice for finger.  (host:0 becomes kdm/host_0)\n"
@@ -443,8 +443,8 @@
 "# Reassign ownership of the console to root, this should disallow\n"
 "# assignment of console output to any random users's xterm. See Xstartup.\n"
 "#\n"
-"#chown root /dev/console\n"
-"#chmod 622 /dev/console\n"
+"chown root /dev/console\n"
+/* "#chmod 622 /dev/console\n" */
 "\n"
 #ifdef _AIX
 "if [ -f /usr/lib/X11/xdm/sessreg ]; then\n"
