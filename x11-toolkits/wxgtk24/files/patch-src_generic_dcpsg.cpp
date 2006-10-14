--- src/generic/dcpsg.cpp.orig	Fri Sep 29 19:57:20 2006
+++ src/generic/dcpsg.cpp	Fri Sep 29 19:58:00 2006
@@ -1146,7 +1146,7 @@
   FILE *file;
 };
 
-static int paps_move_to( FT_Vector* to,
+static int paps_move_to( const FT_Vector* to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -1156,7 +1156,7 @@
   return 0;
 }
 
-static int paps_line_to( FT_Vector*  to,
+static int paps_line_to( const FT_Vector*  to,
 			 void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -1166,8 +1166,8 @@
   return 0;
 }
 
-static int paps_conic_to( FT_Vector*  control,
-			  FT_Vector*  to,
+static int paps_conic_to( const FT_Vector*  control,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
@@ -1179,9 +1179,9 @@
   return 0;
 }
 
-static int paps_cubic_to( FT_Vector*  control1,
-			  FT_Vector*  control2,
-			  FT_Vector*  to,
+static int paps_cubic_to( const FT_Vector*  control1,
+			  const FT_Vector*  control2,
+			  const FT_Vector*  to,
 			  void *user_data)
 {
   OutlineInfo *outline_info = (OutlineInfo*)user_data;
