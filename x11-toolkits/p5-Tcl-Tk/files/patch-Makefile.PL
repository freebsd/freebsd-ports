--- Makefile.PL.orig	Tue Oct 31 22:24:07 2006
+++ Makefile.PL	Tue Oct 31 22:25:37 2006
@@ -23,17 +23,6 @@
     $tclsh = $ENV{'TCLSH_PROG'};
 }
 
-open TCLSH, "$tclsh test-for-tk.tcl|";
-my $res = join '', <TCLSH>;
-
-unless ($res =~ /^ok/m) {
-  die <<EOS;
-
-Your Tcl installation ($tclsh) fails to find Tk package.
-One of possible reasons is missing file 'pkgIndex.tcl' in ..../tk8.4/
-directory; Please check if you can feed 'package require Tk' to tclsh
-EOS
-}
 
 WriteMakefile(
     NAME => "Tcl::Tk",
