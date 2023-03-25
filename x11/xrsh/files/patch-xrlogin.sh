--- xrlogin.sh.orig	2023-03-24 19:02:31.747534000 -0700
+++ xrlogin.sh	2023-03-24 20:15:16.514036000 -0700
@@ -23,8 +23,8 @@
 # Set some defaults.
 progname=`basename $0`
 usage="usage: $progname [-l logname] [-telnet] [emulator options] host"
-netprog="rlogin"
-netprogopts="-8"
+netprog="slogin"
+netprogopts=""
 termprog=xterm
 termprogopts=
 telnet=
