--- src/rxvtperl.xs.orig	Wed Jan 25 21:22:04 2006
+++ src/rxvtperl.xs	Wed Jan 25 23:18:53 2006
@@ -560,7 +560,7 @@
                   char *str = va_arg (ap, char *);
                   int len   = va_arg (ap, int);
 
-                  printf ("pushing str %p:%d\n", str,len);//D
+                  // printf ("pushing str %p:%d\n", str,len);//D
                   XPUSHs (sv_2mortal (newSVpvn (str, len)));
                 }
                 break;
