$OpenBSD: patch-xsel_c,v 1.2 2014/07/07 08:25:16 sthen Exp $

- Format "32" properties use "long", not "int", even on LP64 platforms.
- ensure NUM_TARGETS does not exceed MAX_NUM_TARGETS.
- plug a memory leak in handle_targets()
- sigsetjmp expects a sigjmp_buf type arg, not a jmp_buf type arg

--- xsel.c.orig	2008-02-12 04:50:18 UTC
+++ xsel.c
@@ -15,6 +15,7 @@
 #include "config.h"
 #endif
 
+#include <assert.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
@@ -465,7 +466,7 @@ get_timestamp (void)
  */
 
 /* The jmp_buf to longjmp out of the signal handler */
-static jmp_buf env_alrm;
+static sigjmp_buf env_alrm;
 
 /*
  * alarm_handler (sig)
@@ -1300,14 +1301,16 @@ handle_targets (Display * display, Windo
                 Atom selection, Time time, MultTrack * mparent)
 {
   Atom * targets_cpy;
+  HandleResult r;
 
   targets_cpy = malloc (sizeof (supported_targets));
   memcpy (targets_cpy, supported_targets, sizeof (supported_targets));
 
-  return
-    change_property (display, requestor, property, XA_ATOM, 32,
+  r = change_property (display, requestor, property, XA_ATOM, 32,
                      PropModeReplace, (unsigned char *)targets_cpy,
                      NUM_TARGETS, selection, time, mparent);
+  free(targets_cpy);
+  return r;
 }
 
 /*
@@ -2078,7 +2081,6 @@ main(int argc, char *argv[])
 
   /* Get the NULL atom */
   null_atom = XInternAtom (display, "NULL", False);
-  NUM_TARGETS++;
 
   /* Get the TEXT atom */
   text_atom = XInternAtom (display, "TEXT", False);
@@ -2097,6 +2099,8 @@ main(int argc, char *argv[])
   supported_targets[s++] = XA_STRING;
   NUM_TARGETS++;
 
+  assert(NUM_TARGETS <= MAX_NUM_TARGETS);
+
   /* Get the COMPOUND_TEXT atom.
    * NB. We do not currently serve COMPOUND_TEXT; we can retrieve it but
    * do not perform charset conversion.
