--- Makefile.PL.orig	Tue Jun 20 18:37:12 2000
+++ Makefile.PL	Mon Oct 30 04:27:50 2000
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
 use Gtk::Install::Files;
 use Cwd;
 require '../Depends.pm';
@@ -25,12 +24,12 @@
 	$typemaps, [keys %defs], [@defines], [@headers], $pm);
 
 foreach (@typemaps) {
-	print "Add typemap: $Gtk::Install::Files::CORE/$_\n";
-	push(@$typemaps, cwd() .'/'.$Gtk::Install::Files::CORE . '/'. $_);
+	print "Add typemap: $Gtk::Install::Files::CORE$_\n";
+	push(@$typemaps, '/'.$Gtk::Install::Files::CORE . $_);
 }
 
 push(@defines, @Gtk::Install::Files::defines);
-push(@defines, '-I../build', '-Ibuild', '-I.', '-I../Gtk');
+push(@defines, '-I../build', '-Ibuild', '-I.', '-I'.$Gtk::Install::Files::CORE);
 
 $pm->{'GtkXmHTML.pm'} = '$(INST_ARCHLIBDIR)/XmHTML.pm';
 $pm->{'build/GtkXmHTMLTypes.pm'} = '$(INST_ARCHLIBDIR)/XmHTML/Types.pm';
