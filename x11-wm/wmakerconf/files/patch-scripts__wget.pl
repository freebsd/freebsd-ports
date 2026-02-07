--- scripts/wget.pl.orig	2004-01-25 22:20:31 UTC
+++ scripts/wget.pl
@@ -1,5 +1,5 @@ quit ("Wget not installed") if $wwwget eq "";
 quit ("Wget not installed") if $wwwget eq "";
 
-$rc = system ("$wwwget --quiet -c --tries=0 -O$tmpfile '$url'");
+$rc = system ("$wwwget --q -o $tmpfile '$url'");
 
 quit ("HTTP response error.") if $rc;
