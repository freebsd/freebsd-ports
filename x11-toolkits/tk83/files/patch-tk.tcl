--- ../library/tk.tcl.orig	Fri Jun  7 02:54:55 2002
+++ ../library/tk.tcl
@@ -304,6 +304,7 @@
 	if {[info exists tcl_platform(os)]} {
 	    switch $tcl_platform(os) {
 		"IRIX"  -
+		"FreeBSD" -
 		"Linux" { event add <<PrevWindow>> <ISO_Left_Tab> }
 		"HP-UX" {
 		    # This seems to be correct on *some* HP systems.
