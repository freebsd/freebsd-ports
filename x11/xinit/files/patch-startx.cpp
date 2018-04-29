# remove expr GNUisms: use BRE syntax and remove match, based on
# upstream commit e3bab0cc706880c22f2b205e7abad9d8c0227071, but
# also shield expr from leading dash of X server args.
#
# generate displayname as dictated in the xauth manpage
#
--- startx.cpp.orig	2018-03-10 01:46:03 UTC
+++ startx.cpp
@@ -166,7 +166,7 @@ while [ x"$1" != x ]; do
 	else
 	    XCOMM display must be the FIRST server argument
 	    if [ x"$serverargs" = x ] && @@
-		 expr "$1" : ':[0-9][0-9]*$' > /dev/null 2>&1; then
+		 expr \( "$1" \) : ':[0-9][0-9]*$' > /dev/null 2>&1; then
 		display="$1"
 	    else
 		serverargs="$serverargs $1"
@@ -229,7 +229,7 @@ fi
 XCOMM if no vt is specified add vtarg (which may be empty)
 have_vtarg="no"
 for i in $serverargs; do
-    if expr "$i" : 'vt[0-9][0-9]*$' > /dev/null; then
+    if expr \( "$i" \) : 'vt[0-9][0-9]*$' > /dev/null; then
         have_vtarg="yes"
     fi
 done
@@ -296,9 +296,9 @@ EOF
     XCOMM now add the same credentials to the client authority file
     XCOMM if '$displayname' already exists do not overwrite it as another
     XCOMM server may need it. Add them to the '$xserverauthfile' instead.
-    for displayname in $authdisplay $hostname$authdisplay; do
+    for displayname in $authdisplay $hostname/unix$authdisplay; do
         authcookie=`XAUTH list "$displayname" @@
-        | sed -n "s/.*$displayname[[:space:]*].*[[:space:]*]//p"` 2>/dev/null;
+        | sed -n "s|.*$displayname[[:space:]*].*[[:space:]*]||p"` 2>/dev/null;
         if [ "z${authcookie}" = "z" ] ; then
             XAUTH -q << EOF 
 add $displayname . $mcookie
