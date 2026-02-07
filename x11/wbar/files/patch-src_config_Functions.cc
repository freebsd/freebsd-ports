../src/config/Functions.cc:14:34: error: invalid suffix on literal; C++11 requires a
      space between literal and identifier [-Wreserved-user-defined-literal]
#define ICON_DEFAULT PIXMAPDIR"/"PACKAGE_NAME".png"
                                 ^
                                  
../src/config/Functions.cc:307:38: error: invalid suffix on literal; C++11 requires a
      space between literal and identifier [-Wreserved-user-defined-literal]
            command = PACKAGE_NAME" "DEFAULT_ARGV;

--- src/config/Functions.cc.orig	2012-09-19 02:54:53 UTC
+++ src/config/Functions.cc
@@ -11,7 +11,7 @@
 #include "Run.h"
 #include "OptParser.h"
 
-#define ICON_DEFAULT PIXMAPDIR"/"PACKAGE_NAME".png"
+#define ICON_DEFAULT PIXMAPDIR "/" PACKAGE_NAME ".png"
 
 static const gchar *authors[] =
 {
@@ -304,7 +304,7 @@ void set_config_states(std::string command)
         
         if (command.empty())
         {
-            command = PACKAGE_NAME" "DEFAULT_ARGV;
+            command = PACKAGE_NAME " " DEFAULT_ARGV;
         }
 
         if (argc <= 1 || tmpoptparser.isSet( OptParser::CONFIG ))
