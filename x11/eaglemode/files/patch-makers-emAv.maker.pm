--- makers/emAv.maker.pm.orig	2008-10-29 08:27:34.000000000 +0300
+++ makers/emAv.maker.pm	2008-10-30 00:03:52.000000000 +0300
@@ -87,8 +87,7 @@
 		$options{'xine-lib-dir'} ne '' ? (
 			"--lib-search-dir", $options{'xine-lib-dir'}
 		) : (),
-		"--link"          , "xine",
-		"--link"          , "pthread",
+		"--link"          , "xine ".(`xine-config --libs | tr -d '\\n'`),
 		"--type"          , "cexe",
 		"--name"          , "emAvServerProc_xine",
 		"src/emAv/emAvServerProc_xine.c"
