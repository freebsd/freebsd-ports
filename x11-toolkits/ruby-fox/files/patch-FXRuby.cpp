--- ext/fox/FXRuby.cpp.orig	Thu Mar 21 02:49:53 2002
+++ ext/fox/FXRuby.cpp	Tue Nov 26 03:44:37 2002
@@ -761,8 +761,8 @@
   VALUE retval;
   if(FXRbCatchExceptions){
 #if RUBY_VERSION_CODE < 170
-    retval=rb_rescue2((VALUE(*)()) handle_body, (VALUE) &hArgs,
-                      (VALUE(*)()) handle_rescue, Qnil,
+    retval=rb_rescue2((VALUE(*)(...)) handle_body, (VALUE) &hArgs,
+                      (VALUE(*)(...)) handle_rescue, Qnil,
                       rb_eStandardError, rb_eNameError, 0);
 #else
     retval=rb_rescue2((VALUE(*)(ANYARGS)) handle_body, (VALUE) &hArgs,
