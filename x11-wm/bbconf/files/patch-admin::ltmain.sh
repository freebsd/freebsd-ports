$FreeBSD$

--- admin/ltmain.sh.orig	Tue Oct 30 15:44:54 2001
+++ admin/ltmain.sh	Tue Oct 30 15:44:57 2001
@@ -4609,10 +4609,10 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	#name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
+	#instname="$dir/$name"i
+	#$show "$install_prog $instname $destdir/$name"
+	#$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
