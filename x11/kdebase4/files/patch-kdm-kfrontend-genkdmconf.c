--- kdm/kfrontend/genkdmconf.c.orig	Wed Jun 26 12:37:51 2002
+++ kdm/kfrontend/genkdmconf.c	Wed Jun 26 12:39:42 2002
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
@@ -1054,7 +1054,7 @@
 { "Language",		"de_DE", 0 },
 { "ShowUsers",		"None", 0 },
 { "SelectedUsers",	"root,johndoe", 0 },
-{ "HiddenUsers",	"adm,alias,amanda,apache,bin,bind,daemon,exim,falken,ftp,games,gdm,gopher,halt,httpd,ident,imnadm,ingres,kmem,lp,mail,mailnull,man,mta,mysql,named,news,nfsnobody,nobody,nscd,ntp,operator,pcap,pop,postfix,postgres,qmaild,qmaill,qmailp,qmailq,qmailr,qmails,radvd,reboot,rpc,rpcuser,rpm,sendmail,shutdown,squid,sympa,sync,tty,uucp,xfs,xten", 1 },
+{ "HiddenUsers",	"adm,alias,amanda,apache,bin,bind,daemon,exim,falken,ftp,games,gdm,gopher,halt,httpd,ident,imnadm,ingres,kmem,lp,mail,mailnull,man,mta,mysql,named,news,nfsnobody,nobody,nscd,ntp,operator,pcap,pop,postfix,postgres,qmaild,qmaill,qmailp,qmailq,qmailr,qmails,radvd,reboot,rpc,rpcuser,rpm,sendmail,sshd,shutdown,smmsp,squid,sympa,sync,tty,uucp,www,xfs,xten", 1 },
 { "MinShowUID",		"1000", 0 },
 { "MaxShowUID",		"29999", 0 },
 { "SortUsers",		"false", 0 },
