--- Makefile.PL.orig	Sat May 12 08:53:34 2007
+++ Makefile.PL	Sun Jun 24 01:13:55 2007
@@ -23,25 +23,7 @@
     $tclsh = $ENV{'TCLSH_PROG'};
 }
 
-open TCLSH, "$tclsh test-for-tk.tcl|";
-my $res = join '', <TCLSH>;
 
-unless ($res =~ /^ok1/m) {
-  die <<EOS;
-
-Your Tcl installation ($tclsh) fails to find Tk package.
-One of possible reasons is missing file 'pkgIndex.tcl' in ..../tk8.4/
-directory; Please check if you can feed 'package require Tk' to tclsh
-EOS
-}
-
-unless ($res =~ /^ok2/m) {
-  die <<EOS;
-
-Your Tk installation fails to find snit package.
-Make sure that it is installed within your Tcl/Tk.
-EOS
-}
 
 WriteMakefile(
     NAME => "Tcl::Tk",
