--- Makefile.PL.orig	Tue Jun 20 18:37:29 2000
+++ Makefile.PL	Mon Oct 30 04:15:42 2000
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
 use Gtk::Install::Files;
 use Cwd;
 require '../Depends.pm';
@@ -12,9 +11,9 @@
 
 $pm = {};
 
-$inc = `gtk-config --cflags`;
+$inc = `$ENV{GTK_CONFIG} --cflags`;
 chomp($inc);
-$libs = "-lgtkgl  -lMesaGL -lMesaGLU " . `gtk-config --libs`;
+$libs = "-lgtkgl  -lMesaGL -lMesaGLU " . `$ENV{GTK_CONFIG} --libs`;
 chomp($libs);
 $nomesa = $libs;
 $nomesa =~ s/Mesa//g;
@@ -29,12 +28,12 @@
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
 
 $pm->{'GtkGLArea.pm'} = '$(INST_ARCHLIBDIR)/GLArea.pm';
 $pm->{'build/GtkGLAreaTypes.pm'} = '$(INST_ARCHLIBDIR)/GLArea/Types.pm';
