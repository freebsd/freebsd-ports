--- res/xsetup.sh.orig	2023-06-15 07:30:09 UTC
+++ res/xsetup.sh
@@ -55,8 +55,8 @@ esac
 [ -f $HOME/.xprofile ] && . $HOME/.xprofile
 
 # run all system xinitrc shell scripts.
-if [ -d /etc/X11/xinit/xinitrc.d ]; then
-  for i in /etc/X11/xinit/xinitrc.d/* ; do
+if [ -d /usr/local/etc/X11/xinit/xinitrc.d ]; then
+  for i in /usr/local/etc/X11/xinit/xinitrc.d/* ; do
   if [ -x "$i" ]; then
     . "$i"
   fi
@@ -66,8 +66,8 @@ fi
 # Load Xsession scripts
 # OPTIONFILE, USERXSESSION, USERXSESSIONRC and ALTUSERXSESSION are required
 # by the scripts to work
-xsessionddir="/etc/X11/Xsession.d"
-OPTIONFILE=/etc/X11/Xsession.options
+xsessionddir="/usr/local/etc/X11/Xsession.d"
+OPTIONFILE=/usr/local/etc/X11/Xsession.options
 USERXSESSION=$HOME/.xsession
 USERXSESSIONRC=$HOME/.xsessionrc
 ALTUSERXSESSION=$HOME/.Xsession
@@ -82,12 +82,12 @@ fi
     done
 fi
 
-if [ -d /etc/X11/Xresources ]; then
-  for i in /etc/X11/Xresources/*; do
+if [ -d /usr/local/etc/X11/Xresources ]; then
+  for i in /usr/local/etc/X11/Xresources/*; do
     [ -f $i ] && xrdb -merge $i
   done
-elif [ -f /etc/X11/Xresources ]; then
-  xrdb -merge /etc/X11/Xresources
+elif [ -f /usr/local/etc/X11/Xresources ]; then
+  xrdb -merge /usr/local/etc/X11/Xresources
 fi
 [ -f $HOME/.Xresources ] && xrdb -merge $HOME/.Xresources
 [ -f $XDG_CONFIG_HOME/X11/Xresources ] && xrdb -merge $XDG_CONFIG_HOME/X11/Xresources
