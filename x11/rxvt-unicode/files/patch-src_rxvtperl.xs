--- src/rxvtperl.xs.orig	2018-12-23 11:31:59 UTC
+++ src/rxvtperl.xs
@@ -401,9 +401,10 @@ rxvt_perl_interp::init ()
           "   unshift @INC, '" LIBDIR "';"
           "}"
           ""
-          "use urxvt;"
+          "use urxvt;",
+          0
         };
-        int argc = ecb_array_length (args);
+        int argc = ecb_array_length (args) - 1;
         char **argv = args;
 
         PERL_SYS_INIT3 (&argc, &argv, &environ);
