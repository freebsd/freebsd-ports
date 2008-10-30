--- makers/unicc/plugins/unicc_gnu.pm.orig	2008-10-29 08:27:34.000000000 +0300
+++ makers/unicc/plugins/unicc_gnu.pm	2008-10-30 00:08:33.000000000 +0300
@@ -142,6 +142,7 @@
 		push(@args,GetObjFiles->[$index]);
 	}
 
+	@args = split(/\s+/, join(' ', @args));
 	return PrintAndRun(@args);
 }
 
@@ -178,6 +179,7 @@
 		}
 	}
 
+	@args = split(/\s+/, join(' ', @args));
 	return PrintAndRun(@args);
 }
 
