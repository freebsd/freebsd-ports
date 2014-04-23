--- src/cppstring.cc.orig	2003-05-01 07:42:11 +0800
+++ src/cppstring.cc
@@ -7,7 +7,7 @@
 // #include <except.h>
 #define DEF_BUFFER_SIZE     512
 #define CPPSTRING_ERROR(obj,msg,retval) {obj<<"*** ERROR *** : "<<msg<<std::endl;return retval;}
-std::ostream& operator<<(std::ostream &cou, CppString &str)
+std::ostream& operator<<(std::ostream &cou, const CppString &str)
 {
 	return (cou << str.our_string);
 }
@@ -25,7 +25,7 @@ CppString::~CppString()
 {
 	Clean();
 }
-CppString::CppString(CppString &str) : our_string(0)
+CppString::CppString(const CppString &str) : our_string(0)
 {
 	Clean();
 	(*this)=str.c_str();
@@ -411,10 +411,12 @@ bool CppString::Contains(char ch) const
 CppString& CppString::format(const char *fstr, ...)
 {
 	char *buffer=new char[0x1000]; // 4096
-	char *args=(char*)&fstr+sizeof(fstr);
-	vsprintf(buffer,fstr,args);
+	va_list args;
+	va_start(args,fstr);
+	vsnprintf(buffer,sizeof(buffer),fstr,args);
 	(*this)=buffer;
 	delete[]buffer;
+	va_end(args);
 	return *this;
 }
 // #include <iostream.h>
