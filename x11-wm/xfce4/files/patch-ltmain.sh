--- ltmain.sh.orig	Mon Jun 10 05:25:37 2002
+++ ltmain.sh	Tue Nov 12 03:09:05 2002
@@ -962,6 +962,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1054,14 +1055,14 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -2471,7 +2472,7 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
 	  *)
@@ -4258,10 +4259,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
