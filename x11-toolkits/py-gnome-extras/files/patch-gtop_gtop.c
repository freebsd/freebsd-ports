--- gtop/gtop.c.orig	Wed May 18 00:54:59 2005
+++ gtop/gtop.c	Wed May 18 00:54:12 2005
@@ -44,6 +44,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 
@@ -1316,8 +1317,8 @@ build_siglist(void)
 
 	for(i = 0; i < len; ++i)
 	{
-		p = &glibtop_sys_siglist[i];
 		PyObject* d;
+		p = &glibtop_sys_siglist[i];
 
 		d = PyDict_New();
 		my_dict_add_and_decref(d, "number", PyI_L(p->number));
