--- ./apps/kinfocenter/base/info_fbsd.cpp.orig	2009-04-15 14:25:24.000000000 +0400
+++ ./apps/kinfocenter/base/info_fbsd.cpp	2009-09-22 21:33:38.000000000 +0400
@@ -211,28 +211,17 @@
 	FILE *pipe;
 	QFile *pcicontrol;
 	QString s, cmd;
+	QTextStream *t;
 	QTreeWidgetItem *olditem= NULL;
 
 	pcicontrol = new QFile("/usr/sbin/pciconf");
 
 	if (!pcicontrol->exists()) {
+		QStringList list;
+		list << i18n("Could not find any programs with which to query your system's PCI information");
+		new QTreeWidgetItem(tree, list);
 		delete pcicontrol;
-		pcicontrol = new QFile("/usr/X11R6/bin/scanpci");
-		if (!pcicontrol->exists()) {
-			delete pcicontrol;
-			pcicontrol = new QFile("/usr/X11R6/bin/pcitweak");
-			if (!pcicontrol->exists()) {
-				QStringList list;
-				list << i18n("Could not find any programs with which to query your system's PCI information");
-				new QTreeWidgetItem(tree, list);
-				delete pcicontrol;
-				return true;
-			} else {
-				cmd = "/usr/X11R6/bin/pcitweak -l 2>&1";
-			}
-		} else {
-			cmd = "/usr/X11R6/bin/scanpci";
-		}
+		return true;
 	} else {
 		cmd = "/usr/sbin/pciconf -l -v 2>&1";
 	}
@@ -247,8 +236,19 @@
 		/* This prints out a list of all the pci devies, perhaps eventually we could
 		 parse it as opposed to schlepping it into a listbox */
 
+		t = new QTextStream(pipe, QIODevice::ReadOnly);
+
+		while (true) {
+			s = t->readLine();
+			if (s.isEmpty() )
+				break;
+			QStringList list;
+			list << s;
+			new QTreeWidgetItem(tree, list);
+		}
+
+		delete t;
 		pclose(pipe);
-		GetInfo_ReadfromPipe(tree, cmd.toLatin1(), true);
 	}
 
 	if (!tree->topLevelItemCount()) {
