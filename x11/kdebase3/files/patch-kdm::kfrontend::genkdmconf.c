--- kdm/kfrontend/genkdmconf.c.orig	Mon Nov  5 21:40:03 2001
+++ kdm/kfrontend/genkdmconf.c	Fri Feb 22 19:34:28 2002
@@ -212,7 +212,7 @@
  */
 
 #ifndef HALT_CMD
-# ifdef BSD
+# if defined(BSD) || defined(__FreeBSD__)
 #  define HALT_CMD	"/sbin/shutdown -h now"
 #  define REBOOT_CMD	"/sbin/shutdown -r now"
 # elif defined(__SVR4)
@@ -1605,8 +1605,8 @@
 "chown $USER /dev/console\n"
 #endif
 "\n"
-"#exec sessreg -a -l $DISPLAY "
-#ifdef BSD
+"exec sessreg -a -l $DISPLAY "
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
@@ -1627,8 +1627,8 @@
 "chmod 622 /dev/console\n"
 #endif
 "\n"
-"#exec sessreg -d -l $DISPLAY "
-#ifdef BSD
+"exec sessreg -d -l $DISPLAY "
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
@@ -1658,7 +1658,8 @@
 "	exec xterm -geometry 80x24-0-0 $*\n"
 "	;;\n"
 "    \"\"|default)\n"
-"	exec $HOME/.xsession $*\n"
+"	test -x $HOME/.xsession && exec $HOME/.xsession $*\n"
+"	sess=kde\n"
 "	;;\n"
 "esac\n"
 "\n"
@@ -1781,7 +1782,7 @@
     }
     addKdePath ("UserPath", DEF_USER_PATH);
     addKdePath ("SystemPath", DEF_SYSTEM_PATH);
-    ASPrintf (&newkdmrc, "%s/kdmrc", newdir);
+    ASPrintf (&newkdmrc, "%s/kdmrc.dist", newdir);
     f = Create (newkdmrc, kdmrcmode);
     wrconf (f);
     fclose (f);
