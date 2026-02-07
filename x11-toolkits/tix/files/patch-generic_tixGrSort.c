--- generic/tixGrSort.c.orig	2013-05-13 10:52:04.000000000 +0200
+++ generic/tixGrSort.c	2013-05-13 10:53:38.000000000 +0200
@@ -447,8 +447,8 @@
 	 * Parse the result of the command.
 	 */
 
-	order = strtol(sortInterp->result, &end, 0);
-	if ((end == sortInterp->result) || (*end != 0)) {
+	order = strtol(Tcl_GetStringResult(sortInterp), &end, 0);
+	if ((end == Tcl_GetStringResult(sortInterp)) || (*end != 0)) {
 	    Tcl_ResetResult(sortInterp);
 	    Tcl_AppendResult(sortInterp,
 		    "comparison command returned non-numeric result",
