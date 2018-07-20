./src/core/Main.cc:84:38: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
            command = PACKAGE_NAME" "DEFAULT_ARGV;
                                                 ^

--- src/core/Main.cc.orig	2018-07-20 12:51:16 UTC
+++ src/core/Main.cc
@@ -81,7 +81,7 @@ int main(int argc, char **argv)
 
         if (command.empty())
         {
-            command = PACKAGE_NAME" "DEFAULT_ARGV;
+            command = PACKAGE_NAME " " DEFAULT_ARGV;
         }
 
         if (argc <= 1 || tmpoptparser.isSet( OptParser::CONFIG ))
