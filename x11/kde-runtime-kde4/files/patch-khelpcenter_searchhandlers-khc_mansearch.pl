--- ./khelpcenter/searchhandlers/khc_mansearch.pl.orig	2008-08-02 17:06:48.000000000 +0200
+++ ./khelpcenter/searchhandlers/khc_mansearch.pl	2008-08-02 17:07:03.000000000 +0200
@@ -55,7 +55,7 @@
 while( <MAN> ) {
 #  print "RAW:$_";
   chop;
-  /^([^\s]+)\s+\((.*)\)\s+-\s+(.*)$/;
+  /^([^\s]+)\((.*)\)\s+-\s+(.*)$/;
   my $page = $1;
   my $section = $2;
   my $description = $3;
