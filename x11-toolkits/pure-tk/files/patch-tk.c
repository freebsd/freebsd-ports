--- tk.c.orig	2013-05-14 16:10:31.000000000 +0200
+++ tk.c	2013-05-14 16:13:05.000000000 +0200
@@ -115,8 +115,9 @@
   /* start up a new interpreter */
   if (!(interp = Tcl_CreateInterp())) return false;
   if (Tcl_Init(interp) != TCL_OK) {
-    if (interp->result && *interp->result)
-      set_result(result, interp->result);
+    const char *res = Tcl_GetStringResult(interp);
+    if (res && *res)
+      set_result(result, res);
     else
       set_result(result, "error initializing Tcl");
     tk_stop();
@@ -128,8 +129,9 @@
   /* oddly, there are no `env' variables passed, and this one is needed */
   Tcl_SetVar2(interp, "env", "DISPLAY", getenv("DISPLAY"), TCL_GLOBAL_ONLY);
   if (Tk_Init(interp) != TCL_OK) {
-    if (interp->result && *interp->result)
-      set_result(result, interp->result);
+    const char *res = Tcl_GetStringResult(interp);
+    if (res && *res)
+      set_result(result, res);
     else
       set_result(result, "error initializing Tk");
     tk_stop();
@@ -182,8 +184,9 @@
   if (!cmd) return false;
   strcpy(cmd, s);
   status = Tcl_Eval(interp, cmd);
-  if (interp && interp->result && *interp->result)
-    set_result(result, interp->result);
+  const char *res = Tcl_GetStringResult(interp);
+  if (res && *res)
+    set_result(result, res);
   else if (status == TCL_BREAK)
     set_result(result, "invoked \"break\" outside of a loop");
   else if (status == TCL_CONTINUE)
