
$FreeBSD$

--- ltmain.sh.orig	Tue Jan 22 06:35:12 2002
+++ ltmain.sh	Fri Feb  8 01:27:17 2002
@@ -1799,6 +1799,9 @@
 	  # rhapsody is a little odd...
 	  deplibs="$deplibs -framework System"
 	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
+	  ;;
 	*)
 	  # Add libc to deplibs on all other systems.
 	  deplibs="$deplibs -lc"
@@ -3360,10 +3366,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
