--- libkmid/midfile.cc.orig	Tue Nov 21 10:21:43 2000
+++ libkmid/midfile.cc	Tue Nov 21 11:52:03 2000
@@ -59,6 +59,23 @@
   {
     fprintf(stderr,"ERROR : popen failed : %s\n",cmd);
   }
+#ifdef HAVE_MKSTEMP
+  strcpy(tmpname,"/tmp/KMid.XXXXXXXX");
+  int fd=mkstemp(tmpname);
+  if (fd<0)
+  {
+    pclose(infile);
+    delete cmd;
+    return 1;
+  }
+  FILE *outfile= fdopen(fd,"wb");
+  if (outfile==NULL)
+  {
+    pclose(infile);
+    delete cmd;
+    return 1;
+  }
+#else
   char *tmp=tempnam(NULL,"KMid");
   if (tmp==NULL) 
   {
@@ -74,6 +91,7 @@
     delete cmd;
     return 1;
   }
+#endif
   int n=getc(infile);
   if (n==EOF) 
   {
