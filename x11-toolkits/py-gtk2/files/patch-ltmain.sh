--- ltmain.sh.orig	Mon May 27 06:33:15 2002
+++ ltmain.sh	Fri Nov  8 20:57:04 2002
@@ -1073,8 +1073,16 @@
 	continue
 	;;
 
+      -pthread)
+	compile_command="$compile_command -pthread"
+	finalize_command="$finalize_command -pthread"
+	compiler_flags="$compiler_flags -pthread"
+	continue
+	;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
