--- kcontrol/info/info_fbsd.cpp.orig	Tue Feb 24 12:30:07 2004
+++ kcontrol/info/info_fbsd.cpp	Thu Apr 14 22:37:54 2005
@@ -226,18 +226,17 @@
 {
 	FILE *pipe;
 	QFile *pcicontrol;
-	QTextStream *t;
 	QString s, cmd;
 	QListViewItem *olditem = 0;
 
-	pcicontrol = new QFile("/usr/X11R6/bin/scanpci");
+	pcicontrol = new QFile("/usr/sbin/pciconf");
 
 	if (!pcicontrol->exists()) {
 		delete pcicontrol;
-		pcicontrol = new QFile("/usr/X11R6/bin/pcitweak");
+		pcicontrol = new QFile("/usr/X11R6/bin/scanpci");
 		if (!pcicontrol->exists()) {
 			delete pcicontrol;
-			pcicontrol = new QFile("/usr/sbin/pciconf");
+			pcicontrol = new QFile("/usr/X11R6/bin/pcitweak");
 			if (!pcicontrol->exists()) {
 				QString s;
 				s = i18n("Could not find any programs with which to query your system's PCI information");
@@ -245,13 +244,13 @@
 				delete pcicontrol;
 				return true;
 			} else {
-				cmd = "/usr/sbin/pciconf -l";
+				cmd = "/usr/X11R6/bin/pcitweak -l 2>&1";
 			}
 		} else {
-			cmd = "/usr/X11R6/bin/pcitweak -l 2>&1";
+			cmd = "/usr/X11R6/bin/scanpci";
 		}
 	} else {
-		cmd = "/usr/X11R6/bin/scanpci";
+		cmd = "/usr/sbin/pciconf -l -v 2>&1";
 	}
 	delete pcicontrol;
 
@@ -263,17 +262,8 @@
 		/* This prints out a list of all the pci devies, perhaps eventually we could
 		   parse it as opposed to schlepping it into a listbox */
 
-		t = new QTextStream(pipe, IO_ReadOnly);
-
-		while (true) {
-			s = t->readLine();
-			if ( s.isEmpty() )
-				break;
-			olditem = new QListViewItem(lbox, olditem, s);
-		}
-
-		delete t;
 		pclose(pipe);
+		GetInfo_ReadfromPipe(lbox, cmd.latin1(), true);
 	}
 
 	if (!lbox->childCount()) {
