../src/config/Run.cc:139:31: error: invalid suffix on literal; C++11 requires a space
      between literal and identifier [-Wreserved-user-defined-literal]
              if (system ("killall "PACKAGE_NAME) != 0)
                                                ^

--- src/config/Run.cc.orig	2018-07-20 12:53:00 UTC
+++ src/config/Run.cc
@@ -136,7 +136,7 @@ void Run::stop()
 {
     if (Run::getPID() > 0)
     {
-        if (system ("killall "PACKAGE_NAME) != 0)
+        if (system ("killall " PACKAGE_NAME) != 0)
         {
             std::cout << _("Error kill program: ") << PACKAGE_NAME << std::endl;
         }
