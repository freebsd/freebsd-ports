--- inc/WManager.H.orig	Mon Nov 15 00:28:36 1999
+++ inc/WManager.H	Sun Nov  2 02:38:20 2003
@@ -80,10 +80,10 @@
   
 private:
   Interface* _Interface;
-  string*    _ConfigurationFilename;
+  std::string*    _ConfigurationFilename;
 
   void
-  _ParseConfigurationFile(ifstream* filestream);
+  _ParseConfigurationFile(std::ifstream* filestream);
 
   void
   _TokenizeAndAddToBrowser(char* entry);
