--- kcontrol/arts/arts.cpp.orig	Fri Mar  5 12:15:10 2004
+++ kcontrol/arts/arts.cpp	Fri Mar  5 12:08:16 2004
@@ -541,13 +541,13 @@
 
 	connect(checkProcess, SIGNAL(processExited(KProcess*)),
 	        this, SLOT(slotArtsdExited(KProcess*)));
-	checkProcess->start(KProcess::Block);
-
-	if (latestProcessStatus == 0)
+	if (checkProcess->start(KProcess::Block) == false)
+		realtimePossible =  false;
+	else if (latestProcessStatus == 0)
 		realtimePossible =  true;
 	else
 		realtimePossible =  false;
-	
+
 	checked = true;
 	
 	}
