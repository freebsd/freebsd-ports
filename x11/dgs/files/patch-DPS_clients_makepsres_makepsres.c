--- DPS/clients/makepsres/makepsres.c.orig	2000-01-11 22:25:01.000000000 +0000
+++ DPS/clients/makepsres/makepsres.c
@@ -126,7 +126,7 @@ char *program;
 
 extern char *malloc(), *realloc();
 
-#if !defined(__NetBSD__) && !defined(__FreeBSD__)
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 # if !defined(__GLIBC__)
 extern char *sys_errlist[];
 # else
