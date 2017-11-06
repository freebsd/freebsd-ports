* Obey user's unit preferences when displaying PCI info.
* Use correct units, someone forgot about terabytes
*
--- kinfocenter/Modules/pci/kpci.cpp.orig	2015-06-26 03:17:21 UTC
+++ kinfocenter/Modules/pci/kpci.cpp
@@ -22,6 +22,8 @@ extern "C" {
 #include <QTreeWidget>
 #include <QTreeWidgetItem>
 #include <QFile>
+#include <kglobal.h>
+#include <klocale.h>
 
 static const QString& getNameById(const id2name *const table, int id) {
 	for (int i=0;; i++) {
@@ -238,31 +240,35 @@ static QTreeWidgetItem* addBist(QTreeWid
 }//addBist
 
 static QTreeWidgetItem* addSize(QTreeWidgetItem *parent, QTreeWidgetItem *after, pciaddr_t size) {
+	static bool realUnits = (KGlobal::locale()->binaryUnitDialect() == KLocale::JEDECBinaryDialect);
 	if (size<0x400) {
 		after=create(parent, i18n("Size"), QString("%1 B").arg(static_cast<unsigned long>(size)));
 	}//if
 	else if (size<0x100000) {
-		after=create(parent, i18n("Size"), QString("%1 kiB").arg(static_cast<unsigned long>(size/0x400)));
+		after=create(parent, i18n("Size"), QString(realUnits ? "%1 KB" : "%1 KiB").arg(static_cast<unsigned long>(size/0x400)));
 	}//elif
 	else if (size<0x40000000) {
-		after=create(parent, i18n("Size"), QString("%1 MiB").arg(static_cast<unsigned long>(size/0x100000)));
+		after=create(parent, i18n("Size"), QString(realUnits ? "%1 MB" : "%1 MiB").arg(static_cast<unsigned long>(size/0x100000)));
 	}//elif
 
 #ifdef HAVE_PCIADDR_T64
 
 	else if (size<0x10000000000LL) {
-		after=create(parent, i18n("Size"),QString("%1 GiB").arg(static_cast<unsigned long>(size/0x40000000)));
+		after=create(parent, i18n("Size"),QString(realUnits ? "%1 GB" : "%1 GiB").arg(static_cast<unsigned long>(size/0x40000000)));
 	}//elif
 	else if (size<0x4000000000000LL) {
-		after=create(parent, i18n("Size"),QString("%1 PiB").arg(static_cast<unsigned long>(size/0x10000000000LL)));
+		after=create(parent, i18n("Size"),QString(realUnits ? "%1 TB" : "%1 TiB").arg(static_cast<unsigned long>(size/0x10000000000LL)));
 	}//elif
 	else if (size<0x1000000000000000LL) {
-		after=create(parent, i18n("Size"),QString("%1 EiB").arg(static_cast<unsigned long>(size/0x4000000000000LL)));
+		after=create(parent, i18n("Size"),QString(realUnits ? "%1 PB" : "%1 PiB").arg(static_cast<unsigned long>(size/0x4000000000000LL)));
 	}//elif
+	else {
+		after=create(parent, i18n("Size"),QString(realUnits ? "%1 EB" : "%1 EiB").arg(static_cast<unsigned long>(size/0x1000000000000000LL)));
+	}//else
 
 #else //HAVE_PCIADDR_T64
 	else {
-		after=create(parent, i18n("Size"), QString("%1 GiB").arg(static_cast<unsigned long>(size/0x40000000)));
+		after=create(parent, i18n("Size"), QString(realUnits ? "%1 GB" : "%1 GiB").arg(static_cast<unsigned long>(size/0x40000000)));
 	}//else
 
 #endif //HAVE_PCIADDR_T64
