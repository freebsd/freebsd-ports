--- scripts/wget.pl.orig	Mon Jan 26 07:20:31 2004
+++ scripts/wget.pl	Wed Jun  2 01:56:42 2004
@@ -1,5 +1,5 @@
 quit ("Wget not installed") if $wwwget eq "";
 
-$rc = system ("$wwwget --quiet -c --tries=0 -O$tmpfile '$url'");
+$rc = system ("$wwwget --q -o $tmpfile '$url'");
 
 quit ("HTTP response error.") if $rc;
