$FreeBSD$

--- sys_x11.cc.orig	Thu May 22 13:11:58 2003
+++ sys_x11.cc	Thu May 22 13:14:35 2003
@@ -59,7 +59,7 @@
 
 char cmdline[2048] = "";
 
-void main( int argc, char* argv[] )
+int main( int argc, char* argv[] )
 {
   for( int i=1; i<argc; i++ ) {
     strcat( cmdline, argv[i] );
