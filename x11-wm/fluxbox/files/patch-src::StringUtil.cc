--- src/StringUtil.cc.orig	Wed Jan  9 15:11:20 2002
+++ src/StringUtil.cc	Wed Jan 30 06:54:54 2002
@@ -67,7 +67,7 @@ char *StringUtil::expandFilename(const c
   
 	auto_ptr<char> retval( new char[strlen(filename)+strlen(getenv("HOME"))+2]);
   if (filename[0]=='~') {
-    strcat(retval.get(), getenv("HOME"));
+    strcpy(retval.get(), getenv("HOME"));
     strcat(retval.get(), &filename[1]);
   } else
     return StringUtil::strdup(filename);	//return unmodified value
