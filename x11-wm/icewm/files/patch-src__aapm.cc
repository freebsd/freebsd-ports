--- ./src/aapm.cc.orig	2010-10-31 10:09:36.000000000 -0400
+++ ./src/aapm.cc	2010-11-02 19:56:53.000000000 -0400
@@ -243,6 +243,7 @@
 }
 
 void YApm::AcpiStr(char *s, bool Tool) {
+	size_t len;
     char buf[80], buf2[80], bat_info[250];
     FILE *fd;
     //name of the battery
