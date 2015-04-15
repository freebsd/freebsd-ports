--- Makefile.PL.orig	2014-11-08 16:12:20 UTC
+++ Makefile.PL
@@ -1244,13 +1244,13 @@ EOF
 	$cmd_options{WITH_ICONV} = 0 unless $cmd_options{WITH_XFT}; # iconv is used for xft only
 	if ( $cmd_options{WITH_ICONV} && have_header( "iconv.h")) {
 		print "Checking for presence of libiconv... ";
-		if ( defined find_lib( 'iconv', '', '')) {
-			push @LIBS, 'iconv';
-			print "yes\n";
+		my $ok = compile( "#include <iconv.h>\nint main() { iconv_close(0); return 0; }\n");
+		if ( $ok ) {
+			print "no, but works as part of libc\n";
 		} else {
-			my $ok = compile( "#include <iconv.h>\nint main() { iconv_close(0); return 0; }\n");
-			if ( $ok ) {
-				print "no, but works as part of libc\n";
+			if ( defined find_lib( 'iconv', '', '')) {
+				push @LIBS, 'iconv';
+				print "yes\n";
 			} else {
 				$DEFINES{HAVE_ICONV_H} = undef;
 				$cmd_options{WITH_ICONV} = 0;
