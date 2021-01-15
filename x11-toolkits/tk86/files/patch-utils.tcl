--- ../library/ttk/utils.tcl.orig	2021-01-15 08:02:56.539276000 +0000
+++ ../library/ttk/utils.tcl	2021-01-15 08:03:38.228900000 +0000
@@ -305,7 +305,7 @@
 	bind $bindtag <MouseWheel> "$callback \[expr {-%D}\]"
 	bind $bindtag <Option-MouseWheel> "$callback \[expr {-10*%D}\]"
     } else {
-	bind $bindtag <MouseWheel> "$callback \[expr {-%D/120)}\]"
+	bind $bindtag <MouseWheel> "$callback \[expr {-%D/120}\]"
     }
 }
 
