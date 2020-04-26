--- Makefile.PL.orig	2002-12-13 15:59:56 UTC
+++ Makefile.PL
@@ -16,7 +16,7 @@ WriteMakefile(
 		'trans_cur.mask'	=> '$(INST_LIB)/Tk/trans_cur.mask',
 		'demos/cursor.pl'	=> ($] >= 5.005
 					? '$(INST_ARCHLIB)'
-					: '$(INST_LIB)') . '/Tk/demos/widtrib/cursor.pl',
+					: '$(INST_LIB)') . '/Tk/demos/widtrib/cursorcontrol.pl',
 			},
 	
 	'PREREQ_PM'	=> {
