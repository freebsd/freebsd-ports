--- makers/unicc/unicc_gnu.pl.orig	2008-04-09 14:53:52.000000000 +0400
+++ makers/unicc/unicc_gnu.pl	2008-05-04 20:22:58.000000000 +0400
@@ -322,6 +322,8 @@
 	push(@args,"-o");
 	push(@args,$Objs[$i]);
 
+	@args = split(/\s+/, join(' ', @args));
+
 	print("@args\n");
 	if (system(@args)!=0) { exit(1); }
 }
@@ -390,6 +392,7 @@
 		push(@args,"-Xlinker");
 		push(@args,$ImportLib);
 	}
+	@args = split(/\s+/, join(' ', @args));
 	print("@args\n");
 	if (system(@args)!=0) { exit(1); }
 }
