diff -urN -urN -x .svn ../vendor/wmanager/inc/WManager.H ./inc/WManager.H
--- ../vendor/wmanager/inc/WManager.H	2007-12-11 12:42:04.000000000 +0200
+++ ./inc/WManager.H	2007-12-17 16:00:13.000000000 +0200
@@ -80,17 +80,17 @@
   
 private:
   Interface* _Interface;
-  string*    _ConfigurationFilename;
+  std::string*    _ConfigurationFilename;
 
   void
-  _ParseConfigurationFile(ifstream* filestream);
+  _ParseConfigurationFile(std::ifstream* filestream);
 
   void
   _TokenizeAndAddToBrowser(char* entry);
 
   char*
-  _CutString(char* str,
-	     char* sub);
+  _CutString(const char* str,
+	     const char* sub);
 };
 
 #endif // WManager_H
