commit fc6cc81be41af58ffd996994e1325dd072a9ab34
Author: Eric Anholt <eric@anholt.net>
Date:   Fri Jul 13 15:34:43 2007 -0700

    Use /dev/random to generate the cookie if mcookie is unavailable.
    
    Setting XAUTHORITY without having actually generated a cookie and created
    .Xauthority led to issues if somebody like ssh later came around and made the
    .Xauthority file for their own setup.  So, simply make it so that we never
    fail to create one.

diff --git a/startx.cpp b/startx.cpp
index eba83b8..f4e24fd 100644
--- startx.cpp
+++ startx.cpp
@@ -170,7 +170,6 @@ fi
 
 removelist=
 
-#if defined(HAS_COOKIE_MAKER) && defined(MK_COOKIE)
 XCOMM set up default Xauth info for this machine
 case `uname` in
 Linux*)
@@ -186,7 +185,15 @@ Linux*)
 esac
 
 authdisplay=${display:-:0}
+#if defined(HAS_COOKIE_MAKER) && defined(MK_COOKIE)
 mcookie=`MK_COOKIE`
+#else
+mcookie=`dd if=/dev/random bs=16 count=1 2>/dev/null | hexdump -e \\"%08x\\"`
+if x"$mcookie" = x; then
+                echo "Couldn't create cookie"
+                exit 1
+fi
+#endif
 dummy=0
 
 XCOMM create a file with auth information for the server. ':0' is a dummy.
@@ -215,8 +222,6 @@ EOF
     fi
 done
 
-#endif
-
 #if defined(__SCO__) || defined(__UNIXWARE__)
 if [ "$REMOTE_SERVER" = "TRUE" ]; then
         exec SHELL_CMD ${client}
