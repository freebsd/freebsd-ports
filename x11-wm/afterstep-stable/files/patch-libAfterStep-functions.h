$FreeBSD$

--- libAfterStep/functions.h.orig	2014-04-12 10:22:47.000000000 -0700
+++ libAfterStep/functions.h	2014-04-11 06:32:13.000000000 -0700
@@ -314,7 +314,7 @@
 void init_func_data (FunctionData * data);
 void copy_func_data (FunctionData * dst, FunctionData * src);
 void dup_func_data (FunctionData * dst, FunctionData * src);
-inline FunctionData *create_named_function( int func, char *name);
+FunctionData *create_named_function( int func, char *name);
 void set_func_val (FunctionData * data, int arg, int value);
 int free_func_data (FunctionData * data);
 void destroy_func_data( FunctionData **pdata );
