--- Makefile.PL.orig	Mon Mar 12 14:31:47 2001
+++ Makefile.PL	Mon Mar 12 14:31:54 2001
@@ -1,8 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
-use blib '../Gnome';
-use blib '../GdkImlib';
 use Cwd;
 require '../Depends.pm';
 require '../tools/gendefs.pl';
