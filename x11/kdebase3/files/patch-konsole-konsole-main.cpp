--- konsole/konsole/main.cpp	29 Jun 2003 21:53:11 -0000	1.243.2.3
+++ konsole/konsole/main.cpp	24 Aug 2003 21:44:02 -0000
@@ -123,6 +123,7 @@ public:
 };


+extern void TEPtyInit();

 /* --| main |------------------------------------------------------ */
 int main(int argc, char* argv[])
@@ -137,6 +138,7 @@ int main(int argc, char* argv[])
   bool scrollbaron = true;
   QCString wname = PACKAGE;

+  TEPtyInit();

   KAboutData aboutData( PACKAGE, I18N_NOOP("Konsole"),
     VERSION, description, KAboutData::License_GPL_V2,
