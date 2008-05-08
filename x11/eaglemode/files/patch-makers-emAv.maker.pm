--- makers/emAv.maker.pm.orig	2008-04-09 14:53:52.000000000 +0400
+++ makers/emAv.maker.pm	2008-05-04 20:03:19.000000000 +0400
@@ -89,7 +89,7 @@
 		$options{'xine-lib-dir'} ne '' ? (
 			"--lib-search-dir", $options{'xine-lib-dir'}
 		) : (),
-		"--link"          , "xine",
+		"--link"          , "xine ".(`xine-config --libs | tr -d '\\n'`),
 		"--type"          , "cexe",
 		"--name"          , "emAvServerProc_xine",
 		"src/emAv/emAvServerProc_xine.c"
