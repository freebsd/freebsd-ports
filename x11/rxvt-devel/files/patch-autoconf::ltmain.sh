--- autoconf/ltmain.sh.orig	Sat Oct  6 11:24:55 2001
+++ autoconf/ltmain.sh	Sat Oct  6 11:29:53 2001
@@ -4093,11 +4093,6 @@
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
