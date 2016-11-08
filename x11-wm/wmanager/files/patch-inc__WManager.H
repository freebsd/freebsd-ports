--- inc/WManager.H.orig	1999-11-14 15:28:36 UTC
+++ inc/WManager.H
@@ -80,17 +80,17 @@ public:
   
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
