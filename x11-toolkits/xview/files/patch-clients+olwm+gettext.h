--- ./clients/olwm/gettext.h.orig	Tue Jun 29 07:11:46 1993
+++ ./clients/olwm/gettext.h	Sat Apr  1 18:26:06 2000
@@ -27,7 +27,11 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/param.h>
- 
+
+#ifndef LC_MESSAGES
+#define LC_MESSAGES 0
+#endif
+
 struct domain_binding {
     char    *domain_name;
     char    *binding;
