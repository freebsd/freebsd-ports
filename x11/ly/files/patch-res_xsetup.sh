--- res/xsetup.sh.orig	2019-11-13 13:46:11 UTC
+++ res/xsetup.sh
@@ -55,8 +55,8 @@ esac
 [ -f $HOME/.xprofile ] && . $HOME/.xprofile
 
 # run all system xinitrc shell scripts.
-if [ -d /etc/X11/xinit/xinitrc.d ]; then
-  for i in /etc/X11/xinit/xinitrc.d/* ; do
+if [ -d %%LOCALBASE%%/etc/X11/xinit/xinitrc.d ]; then
+  for i in %%LOCALBASE%%/etc/X11/xinit/xinitrc.d/* ; do
   if [ -x "$i" ]; then
     . "$i"
   fi
@@ -66,8 +66,8 @@ fi
 # Load Xsession scripts
 # OPTIONFILE, USERXSESSION, USERXSESSIONRC and ALTUSERXSESSION are required
 # by the scripts to work
-xsessionddir="/etc/X11/Xsession.d"
-OPTIONFILE=/etc/X11/Xsession.options
+xsessionddir="%%LOCALBASE%%/etc/X11/Xsession.d"
+OPTIONFILE=%%LOCALBASE%%/etc/X11/Xsession.options
 USERXSESSION=$HOME/.xsession
 USERXSESSIONRC=$HOME/.xsessionrc
 ALTUSERXSESSION=$HOME/.Xsession
@@ -82,12 +82,12 @@ if [ -d "$xsessionddir" ]; then
     done
 fi
 
-if [ -d /etc/X11/Xresources ]; then
-  for i in /etc/X11/Xresources/*; do
+if [ -d %%LOCALBASE%%/etc/X11/Xresources ]; then
+  for i in %%LOCALBASE%%/etc/X11/Xresources/*; do
     [ -f $i ] && xrdb -merge $i
   done
-elif [ -f /etc/X11/Xresources ]; then
-  xrdb -merge /etc/X11/Xresources
+elif [ -f %%LOCALBASE%%/etc/X11/Xresources ]; then
+  xrdb -merge %%LOCALBASE%%/etc/X11/Xresources
 fi
 [ -f $HOME/.Xresources ] && xrdb -merge $HOME/.Xresources
 
