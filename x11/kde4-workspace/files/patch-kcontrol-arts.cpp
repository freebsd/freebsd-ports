Index: kcontrol/arts/arts.cpp
===================================================================
RCS file: /home/kde/kdebase/kcontrol/arts/arts.cpp,v
retrieving revision 1.100
diff -u -3 -p -r1.100 arts.cpp
--- kcontrol/arts/arts.cpp	8 Nov 2003 23:43:47 -0000	1.100
+++ kcontrol/arts/arts.cpp	29 Jan 2004 11:59:29 -0000
@@ -51,6 +51,7 @@
 //#include <kparts/componentfactory.h>
 //#include "midi.h"
 #include "arts.h"
+#include <arts/artsversion.h>
 
 extern "C" {
 	void init_arts();
@@ -601,7 +602,11 @@ void init_arts()
 	config->setGroup("Arts");
 	bool startServer = config->readBoolEntry("StartServer",true);
 	bool startRealtime = config->readBoolEntry("StartRealtime",true);
+#if ARTS_MAJOR_VERSION >= 1 && ARTS_MINOR_VERSION >= 2
 	QString args = config->readEntry("Arguments","-F 10 -S 4096 -s 60 -m artsmessage -c drkonqi -l 3 -f");
+#else
+	QString args = config->readEntry("Arguments","-F 10 -S 4096 -s 60 -m artsmessage -l 3 -f");
+#endif
 
 	delete config;
 
@@ -652,7 +657,11 @@ QString KArtsModule::createArgs(bool net
 		args += QChar(' ') + addOptions;
 
 	args += QString::fromLatin1(" -m artsmessage");
+
+#if ARTS_MAJOR_VERSION >= 1 && ARTS_MINOR_VERSION >= 2
 	args += QString::fromLatin1(" -c drkonqi");
+#endif
+
 	args += QString::fromLatin1(" -l 3");
 	args += QString::fromLatin1(" -f");
 
