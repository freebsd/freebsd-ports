--- khelpcenter/searchhandlers/khc_mansearch.pl.orig	Mon Dec 18 14:35:13 2006
+++ khelpcenter/searchhandlers/khc_mansearch.pl	Mon Dec 18 14:35:37 2006
@@ -55,7 +55,7 @@
 while( <MAN> ) {
 #  print "RAW:$_";
   chop;
-  /^([^\s]+)\s+\((.*)\)\s+-\s+(.*)$/;
+  /^([^\s]+)\((.*)\)\s+-\s+(.*)$/;
   my $page = $1;
   my $section = $2;
   my $description = $3;
