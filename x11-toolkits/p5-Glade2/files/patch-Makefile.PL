--- Makefile.PL.orig	Tue Jun 20 18:35:46 2000
+++ Makefile.PL	Mon Oct 30 03:49:43 2000
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
 use Gtk::Install::Files;
 use Cwd;
 require '../Depends.pm';
@@ -31,12 +30,12 @@
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
 
 $pm->{'GladeXML.pm'} = '$(INST_ARCHLIBDIR)/GladeXML.pm';
 $pm->{'build/GtkGladeXMLTypes.pm'} = '$(INST_ARCHLIBDIR)/GladeXML/Types.pm';
@@ -105,7 +104,6 @@
 	'INC' => $inc,
 	'LIBS' => [$libs],
 	'OBJECT' => $object,
-	'OPTIMIZE' => '-O2 -g',
 	'clean' => {FILES => join(' ', @clean) },
 	#'LDFROM' => $ldfrom,
 	'depend' => $depend,
