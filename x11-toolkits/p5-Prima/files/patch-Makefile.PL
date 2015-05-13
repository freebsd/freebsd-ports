--- Makefile.PL.orig	2015-04-10 19:17:48 UTC
+++ Makefile.PL
@@ -1269,13 +1269,13 @@ EOF
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
@@ -2062,8 +2062,8 @@ sub install
 	my $t = $self->SUPER::install(@_);
 	my $n = $t =~ s[
 		(pure_\w+_install.*?)                       # 1
-		(INST_ARCHLIB\)\s+)\$\(DEST(\w+)\)(.*?)     # 2,3,4
-		(INST_BIN\)\s+)\$\(DEST(\w+)\)(.*?)         # 5,6,7
+		(INST_ARCHLIB\)"?\s+"?)\$\(DEST(\w+)\)(.*?)     # 2,3,4
+		(INST_BIN\)"?\s+"?)\$\(DEST(\w+)\)(.*?)         # 5,6,7
 		(.*?)                                       # 8
 		\n\n
 	][
