--- makeh.c.orig	2024-09-12 09:44:33 UTC
+++ makeh.c
@@ -16,7 +16,7 @@
     printf("};\n\n");
 }
 
-main()
+int main()
 {
     FILE *fp;
     char prefix[BUFSIZ];
