--- ./kdm/kfrontend/genkdmconf.c.orig	2010-07-06 10:54:31.000000000 +0400
+++ ./kdm/kfrontend/genkdmconf.c	2010-07-30 22:23:28.920432715 +0400
@@ -45,9 +45,6 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/param.h>
-#ifdef BSD
-# include <utmp.h>
-#endif
 
 #define WANT_CONF_GEN
 #include <config.ci>
@@ -1857,7 +1854,7 @@
 #else
 # ifdef BSD
             delstr(file, "\n"
-"exec sessreg -a -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n") |
+"exec sessreg -a -l $DISPLAY -x */Xservers $USER\n" ) |
 # endif
 #endif /* _AIX */
             delstr(file, "\n"
@@ -1906,7 +1903,7 @@
 #else
 # ifdef BSD
         delstr(file, "\n"
-"exec sessreg -d -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n") |
+"exec sessreg -d -l $DISPLAY -x */Xservers $USER\n" ) |
 # endif
 #endif /* _AIX */
         delstr(file, "\n"
