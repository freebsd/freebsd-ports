--- ltmain.sh.orig	Fri Nov  8 15:40:11 2002
+++ ltmain.sh	Tue Dec  3 18:47:10 2002
@@ -1082,8 +1082,16 @@
 	continue
 	;;
 
+      -pthread)
+       compile_command="$compile_command -pthread"
+       finalize_command="$finalize_command -pthread"
+       compiler_flags="$compiler_flags -pthread"
+       continue
+       ;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -2397,6 +2405,9 @@
 	    # problems, so we reset it completely
 	    verstring=""
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    verstring="0.0"
 	    ;;
@@ -4327,10 +4338,12 @@
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
