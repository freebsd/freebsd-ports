--- Makefile.PL.orig	2015-08-05 07:18:10 UTC
+++ Makefile.PL
@@ -1270,13 +1270,13 @@ EOF
 	$cmd_options{WITH_ICONV} = 0 unless $cmd_options{WITH_XFT}; # iconv is used for xft only
 	if ( $cmd_options{WITH_ICONV} && have_header( "iconv.h")) {
 		printlog "Checking for presence of libiconv... ";
-		if ( defined find_lib( 'iconv', '', '')) {
-			push @LIBS, 'iconv';
-			printlog "yes\n";
+		my $ok = compile( "#include <iconv.h>\nint main() { iconv_close(0); return 0; }\n");
+		if ( $ok ) {
+			printlog "no, but works as part of libc\n";
 		} else {
-			my $ok = compile( "#include <iconv.h>\nint main() { iconv_close(0); return 0; }\n", 1, $Config{cccdlflags});
-			if ( $ok ) {
-				printlog "no, but works as part of libc\n";
+			if ( defined find_lib( 'iconv', '', '')) {
+				push @LIBS, 'iconv';
+				printlog "yes\n";
 			} else {
 				$DEFINES{HAVE_ICONV_H} = undef;
 				$cmd_options{WITH_ICONV} = 0;
