--- ax.C.orig	Tue Mar 13 21:42:10 2001
+++ ax.C	Mon Dec 16 20:37:56 2002
@@ -18,6 +18,7 @@
 
 #include "ax.h"
 
+using namespace std;
 
 ///////////////////////////////////////////////////////////////////////////////
 //
@@ -713,7 +714,7 @@
 ///////////////////////////////////////////////////////////////////////////////
 
 
-void main(int argc, char** argv)
+int main(int argc, char** argv)
 {
   Access ax;
   ax.QueryServer();
