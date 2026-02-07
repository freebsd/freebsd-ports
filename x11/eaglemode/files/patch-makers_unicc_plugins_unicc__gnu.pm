Note that this plugin is used for both gnu and clang build.

--- makers/unicc/plugins/unicc_gnu.pm.orig	2021-07-11 05:50:52 UTC
+++ makers/unicc/plugins/unicc_gnu.pm
@@ -35,7 +35,7 @@ my $IsWinOrCygwin;
 my $IsDarwin;
 
 {
-	my $s=`gcc -dumpversion`; # Examples: "4.3", "2.95.3"
+	my $s=`$ENV{'CC'} -dumpversion`; # Examples: "4.3", "2.95.3"
 	if ($? != 0) { exit(1); }
 	for (;; $s=substr($s,1)) {
 		if (length($s)==0) { die("Cannot determine GCC version, stopped"); }
@@ -112,9 +112,9 @@ sub Compile
 		push(@args,("-o",GetObjFiles->[$index]));
 	}
 	else {
-		push(@args,"gcc");
+		push(@args,$isCpp ? $ENV{'CXX'} : $ENV{'CC'});
 		if (HaveDebug) { push(@args,"-g"); }
-		push(@args,"-O2");
+		push(@args,grep /./, split(/\s+/, $isCpp ? $ENV{'CXXFLAGS'} : $ENV{'CFLAGS'}));
 		if ($isCpp && $GccVersion>=4.7 && $GccVersion<6.1) {
 			push(@args,"-std=c++11");
 		}
@@ -166,7 +166,8 @@ sub Link
 		push(@args,(@{GetObjFiles()}));
 	}
 	else {
-		push(@args,"gcc");
+		push(@args,HaveCppLib ? $ENV{'CXX'} : $ENV{'CC'});
+		push(@args,grep /./, split(/\s+/, $ENV{'LDFLAGS'}));
 		if (HaveDebug) { push(@args,"-g"); }
 		if ($type eq 'dynlib') {
 			push(@args,$IsDarwin ? "-dynamiclib" : "-shared");
@@ -182,7 +183,6 @@ sub Link
 		foreach my $s (@{GetLinkNames()}) { push(@args,"-l$s"); }
 		if ($IsCygwin && -e "/lib/libcygipc.a") { push(@args,"-lcygipc"); }
 		if (HaveMath) { push(@args,"-lm"); }
-		if (HaveCppLib) { push(@args,"-lstdc++"); }
 		push(@args,"-o");
 		push(@args,GetTgtFile);
 		if ($IsWinOrCygwin and $type eq "dynlib") {
