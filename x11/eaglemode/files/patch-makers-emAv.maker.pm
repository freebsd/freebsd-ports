--- makers/emAv.maker.pm.orig	2008-05-23 08:42:14.000000000 +0400
+++ makers/emAv.maker.pm	2008-06-02 19:16:54.000000000 +0400
@@ -89,8 +89,7 @@
 		$options{'xine-lib-dir'} ne '' ? (
 			"--lib-search-dir", $options{'xine-lib-dir'}
 		) : (),
-		"--link"          , "xine",
-		"--link"          , "pthread",
+		"--link"          , "xine ".(`xine-config --libs | tr -d '\\n'`),
 		"--type"          , "cexe",
 		"--name"          , "emAvServerProc_xine",
 		"src/emAv/emAvServerProc_xine.c"
