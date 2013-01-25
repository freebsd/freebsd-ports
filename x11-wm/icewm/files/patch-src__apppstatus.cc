Fix clang build errors

http://icewm.cvs.sourceforge.net/viewvc/icewm/icewm-1.2/src/apppstatus.cc?r1=1.24.2.1.2.4&r2=1.24.2.1.2.5&pathrev=icewm-1-3-BRANCH

--- src/apppstatus.cc	2009/11/08 19:24:08	1.24.2.1.2.4
+++ src/apppstatus.cc	2010/12/25 15:29:53	1.24.2.1.2.5
@@ -82,7 +82,9 @@
 }
 
 NetStatus::~NetStatus() {
-    delete[] color;
+    delete color[0];
+    delete color[1];
+    delete color[2];
     delete[] ppp_in;
     delete[] ppp_out;
     delete fUpdateTimer;
