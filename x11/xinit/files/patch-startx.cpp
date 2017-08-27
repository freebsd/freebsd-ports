# remove expr GNUisms: use BRE syntax and remove match, based on
# upstream commit e3bab0cc706880c22f2b205e7abad9d8c0227071, but
# also shield expr from leading dash of X server args.
#
# generate displayname as dictated in the xauth manpage
#
--- startx.cpp.orig	2014-09-11 17:31:42 UTC
+++ startx.cpp
@@ -154,7 +154,7 @@ while [ x"$1" != x ]; do
 	else
 	    XCOMM display must be the FIRST server argument
 	    if [ x"$serverargs" = x ] && @@
-		 expr "$1" : ':[0-9][0-9]*$' > /dev/null 2>&1; then
+		expr \( "$1" \) : ':[0-9][0-9]*$' > /dev/null 2>&1; then
 		display="$1"
 	    else
 		serverargs="$serverargs $1"
@@ -193,7 +193,7 @@ if [ x"$server" = x ]; then
     XCOMM the startx session being seen as inactive:
     XCOMM "https://bugzilla.redhat.com/show_bug.cgi?id=806491"
     tty=$(tty)
-    if expr match "$tty" '^/dev/tty[0-9]\+$' > /dev/null; then
+    if expr "$tty" : '/dev/tty[0-9][0-9]*$' > /dev/null; then
         tty_num=$(echo "$tty" | grep -oE '[0-9]+$')
         vtarg="vt$tty_num"
     fi
@@ -217,7 +217,7 @@ fi
 XCOMM if no vt is specified add vtarg (which may be empty)
 have_vtarg="no"
 for i in $serverargs; do
-    if expr match "$i" '^vt[0-9]\+$' > /dev/null; then
+    if expr \( "$i" \) : 'vt[0-9][0-9]*$' > /dev/null; then
         have_vtarg="yes"
     fi
 done
@@ -283,10 +283,10 @@ EOF
 
     XCOMM now add the same credentials to the client authority file
     XCOMM if '$displayname' already exists do not overwrite it as another
-    XCOMM server man need it. Add them to the '$xserverauthfile' instead.
-    for displayname in $authdisplay $hostname$authdisplay; do
+    XCOMM server may need it. Add them to the '$xserverauthfile' instead.
+    for displayname in $authdisplay $hostname/unix$authdisplay; do
         authcookie=`XAUTH list "$displayname" @@
-        | sed -n "s/.*$displayname[[:space:]*].*[[:space:]*]//p"` 2>/dev/null;
+        | sed -n "s|.*$displayname[[:space:]*].*[[:space:]*]||p"` 2>/dev/null;
         if [ "z${authcookie}" = "z" ] ; then
             XAUTH -q << EOF 
 add $displayname . $mcookie
