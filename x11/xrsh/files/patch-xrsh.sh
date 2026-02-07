--- xrsh.sh.orig	2023-03-24 19:02:31.751499000 -0700
+++ xrsh.sh	2023-03-24 20:10:01.927030000 -0700
@@ -3,7 +3,7 @@
 # Some System V systems don't understand the #! construct.  
 #   If your system does understand it, put ": " at the beginning of the line.
 #
-XRSH_VER='xrsh version 5.92'
+XRSH_VER='xesh version 5.92'
 XRSH_RCS='$Header: /usr/home/jjd/xrsh/RCS/xrsh.sh,v 1.16 1996/06/27 15:59:48 jjd Exp $'
 XRSH_TIME='Time-stamp: <1998-01-31 12:08:36 jjd>'
 #
@@ -233,8 +233,11 @@
     command="$command $xcmdargs"
 fi
 
+rsh=`which ssh`
+if [ -x $rsh ]; then
+    rsh=ssh
 # Some System V hosts have rsh as "restricted shell" and ucb rsh is remsh
-if [ -r /usr/bin/remsh ]; then
+elif [ -r /usr/bin/remsh ]; then
     rsh=remsh
 elif [ -f /usr/bin/rcmd ]; then       # SCO Unix uses "rcmd" instead of rsh
     rsh=rcmd
@@ -244,6 +247,7 @@
 
 # Construct the new $DISPLAY for the remote client
 
+
 # The following paragraph of IFS based code replaces sed and 
 #    runs faster because it doesn't fork.  It also handles the arp stuff.
 # newdisplay="`echo $DISPLAY | sed \"s/^[^:]*:/${localhost}:/\"`"
@@ -300,7 +304,7 @@
 done
 
 
-
+test $rsh != ssh &&
 # Use $XRSH_AUTH_TYPE to determine whether to run xhost, xauth, 
 # propagate $XAUTHORITY to the remote host, or do nothing
 case ${XRSH_AUTH_TYPE-$default_auth_type} in
@@ -390,8 +394,13 @@
 # Don't use -n to rsh because SG IRIX doesn't support it.  
 # Use < /dev/null instead.
 if [ "$debug" ]; then
+  if [ $rsh = ssh ]; then
+    echo "Executing \"$command\" on $clienthost"
+    $rsh $clienthost $rshoptions /bin/csh -cf "\"$authenv $xhostvar $passenvs $command\"" < /dev/null
+  else
     echo "Executing \"$command\" on $clienthost with DISPLAY=$newdisplay"
     $rsh $clienthost $rshoptions /bin/csh -cf "\"setenv DISPLAY $newdisplay; $authenv $xhostvar $passenvs $command\"" < /dev/null
+  fi
 else
 #
 # The redirection inside the innermost quotes is done by csh.  The outer
@@ -408,6 +417,10 @@
 # We would like the last '>' to be '>&' or equivalent, but that would make this
 # code dependent on what flavor of shell the user uses on the remote host
 #
+  if [ $rsh = ssh ]; then
+    exec $rsh  $clienthost $rshoptions exec /bin/csh -cf "\"$authenv $xhostvar $passenvs exec $command < /dev/null >>& $XRSH_RSH_ERRORS \" < /dev/null > /dev/null " < /dev/null &
+  else
     exec $rsh  $clienthost $rshoptions exec /bin/csh -cf "\"setenv DISPLAY $newdisplay; $authenv $xhostvar $passenvs exec $command < /dev/null >>& $XRSH_RSH_ERRORS \" < /dev/null > /dev/null " < /dev/null &
+  fi
 
 fi
