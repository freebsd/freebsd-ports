--- setconfdir.pl.orig	Fri Nov 25 17:15:32 2005
+++ setconfdir.pl	Fri Nov 25 17:15:44 2005
@@ -16,8 +16,8 @@
 
 	foreach(<SKEL>) {
 		chomp;
-		if(/^\$CONFDIR\=/) {
-			$_ = "\$CONFDIR=\"$CONFDIR\"";
+		if(/^\CONFDIR\=/) {
+			$_ = "\CONFDIR=\"$CONFDIR\"";
 		}
 		print OUT "$_\n";
 	}
