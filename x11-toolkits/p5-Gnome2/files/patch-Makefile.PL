--- Makefile.PL.orig	Wed Dec 10 07:32:09 2003
+++ Makefile.PL	Wed Jan  7 16:02:44 2004
@@ -35,7 +35,8 @@
            # it's recent enough, too 
            . "use Glib '$build_reqs{'perl-Glib'}';"
            . "use Gtk2 '$build_reqs{'perl-Gtk2'}';"
-           . "use Gnome2::VFS '$build_reqs{'perl-Gnome2-VFS'}';"
+#  this will cause ExtUtils::PkgConfig fail
+#           . "use Gnome2::VFS '$build_reqs{'perl-Gnome2-VFS'}';"
            . "1") {
    warn "$@\n";
    WriteMakefile(
