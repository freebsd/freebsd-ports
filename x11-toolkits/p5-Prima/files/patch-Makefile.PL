--- Makefile.PL.orig	2016-09-18 18:14:36 UTC
+++ Makefile.PL
@@ -1428,13 +1428,13 @@ sub setup_iconv
 {
 	if ( have_header( "iconv.h")) {
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
