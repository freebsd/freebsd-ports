--- kdm/kfrontend/genkdmconf.c.orig	Sun Nov 28 18:26:14 2004
+++ kdm/kfrontend/genkdmconf.c	Thu Dec  2 00:41:46 2004
@@ -578,7 +578,7 @@
 "# by Xsetup usually.\n"
 "# This is not required if you use PAM with the pam_console module.\n"
 "#\n"
-"#chown $USER /dev/console\n"
+"chown $USER /dev/console\n"
 "\n"
 #ifdef _AIX
 "# We create a pseudodevice for finger.  (host:0 becomes xdm/host_0)\n"
@@ -619,8 +619,8 @@
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
@@ -667,7 +667,9 @@
 "  */csh|*/tcsh)\n"
 "    # [t]cshrc is always sourced automatically.\n"
 "    # Note that sourcing csh.login after .cshrc is non-standard.\n"
-"    eval `$SHELL -c 'if (-f /etc/csh.login) source /etc/csh.login > /dev/null; if (-f ~/.login) source ~/.login > /dev/null; /bin/sh -c export'`\n"
+"    set -a\n"
+"    eval `$SHELL -c 'if (-f /etc/csh.login) source /etc/csh.login >& /dev/null; if (-f ~/.login) source ~/.login >& /dev/null; printenv | egrep -v \"^(TERM|SHLVL)=\"'`\n"
+"    set +a\n"
 "    ;;\n"
 "  *) # Plain sh, ksh, and anything we don't know.\n"
 "    [ -f /etc/profile ] && . /etc/profile\n"
