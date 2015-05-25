--- demos/dragger.tcl	Mon Sep 11 12:01:58 2000
+++ demos/dragger.tcl.new	Sun Mar 14 14:36:20 2004
@@ -32,9 +32,9 @@
 # $Id: demo.tcl,v 1.1 1997/09/17 21:10:23 donal Exp donal $
 
 # Now we make cunning use of the backslash/shell trick \
-[ -x `dirname $0`/../shapewish ] && exec `dirname $0`/../shapewish $0 ${1+"$@"} || exec wish8.0 $0 ${1+"$@"} || { echo "`basename $0`: couldn't start wish" >&2 ; exit 1; }
+[ -x `dirname $0`/../shapewish ] && exec `dirname $0`/../shapewish $0 ${1+"$@"} || exec %%WISH%% $0 ${1+"$@"} || { echo "`basename $0`: couldn't start wish" >&2 ; exit 1; }
 
-set dir [file join [pwd] [file dirname [info script]] ..]
+set dir [file join [pwd] [file dirname [info script]]]
 lappend auto_path [file join $dir ..]
 package require Shape
 
