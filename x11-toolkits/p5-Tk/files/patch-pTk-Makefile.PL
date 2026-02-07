--- pTk/Makefile.PL.orig	Fri Jun 11 15:21:32 2004
+++ pTk/Makefile.PL	Fri Jun 11 15:21:57 2004
@@ -12,7 +12,7 @@
     'OBJECT'	=> '$(O_FILES)',
     macro	=> { WINARCH     => $win_arch },
     'DEFINE'	=> $define,
-    'INC'	=> "$inc -I. -Ibitmaps",
+    'INC'	=> "$inc -I. -Ibitmaps -I%%LOCALBASE%%/include",
     'SKIP'	=> [qw( distclean dist makeaperl xs_o)],
     'clean'	=> {'FILES' => 'libpTk$(LIB_EXT)'}
 );
