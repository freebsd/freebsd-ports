--- intl/dcigettext.c.orig	Sat Jun 12 01:13:19 2004
+++ intl/dcigettext.c	Sat Jun 12 01:14:54 2004
@@ -987,11 +987,7 @@
   p = translation;
   while (index-- > 0)
     {
-#ifdef _LIBC
       p = __rawmemchr (p, '\0');
-#else
-      p = strchr (p, '\0');
-#endif
       /* And skip over the NUL byte.  */
       p++; 
