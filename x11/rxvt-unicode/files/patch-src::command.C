--- src/command.C.orig	Wed Dec 29 20:09:31 2004
+++ src/command.C	Wed Dec 29 22:07:49 2004
@@ -2716,7 +2716,9 @@
       if (len == (size_t)-2)
         {
           // the mbstate stores incomplete sequences. didn't know this :/
+#if __FreeBSD_version>502110
           cmdbuf_ptr = cmdbuf_endp;
+#endif
           break;
         }
 
