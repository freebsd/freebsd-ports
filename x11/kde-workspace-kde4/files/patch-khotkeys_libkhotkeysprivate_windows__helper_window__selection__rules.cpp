--- khotkeys/libkhotkeysprivate/windows_helper/window_selection_rules.cpp.orig	2018-08-30 10:04:38 UTC
+++ khotkeys/libkhotkeysprivate/windows_helper/window_selection_rules.cpp
@@ -91,7 +91,7 @@ bool Windowdef_simple::is_substr_match( 
         case NOT_IMPORTANT :
           return true;
         case CONTAINS :
-          return str1_P.contains( str2_P ) > 0;
+          return bool(str1_P.contains( str2_P ));
         case IS :
           return str1_P == str2_P;
         case REGEXP :
@@ -100,7 +100,7 @@ bool Windowdef_simple::is_substr_match( 
           return rg.indexIn( str1_P ) >= 0;
             }
         case CONTAINS_NOT :
-          return str1_P.contains( str2_P ) == 0;
+          return !str1_P.contains( str2_P );
         case IS_NOT :
           return str1_P != str2_P;
         case REGEXP_NOT :
