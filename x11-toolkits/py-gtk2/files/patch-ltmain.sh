--- ltmain.sh.orig	Sun Mar 23 21:36:18 2003
+++ ltmain.sh	Sun Mar 23 21:38:57 2003
@@ -1085,8 +1085,16 @@
 	continue
 	;;
 
+	-pthread)
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
 
