--- ksysguard~/gui/SensorDisplayLib/ListView.cc	2009-12-14 12:43:42.000000000 +0200
+++ ksysguard/gui/SensorDisplayLib/ListView.cc	2011-02-18 12:49:41.000000000 +0200
@@ -108,6 +108,8 @@
     return Time;
   else if ( type == "M" )
     return DiskStat;
+  else if ( type == "KB" || type == "KByte" )
+    return KByte;
   else
     return Text;
 }
@@ -115,6 +117,8 @@
 void
 ListView::answerReceived(int id, const QList<QByteArray>& answer)
 {
+	unsigned long kbytes;
+	float sbytes;
 	/* We received something, so the sensor is probably ok. */
 	sensorError(id, false);
 
@@ -139,7 +143,12 @@
 			}
 
 			for(uint i =0 ; i < colTypes.count(); i++) {
-				mColumnTypes.append(convertColumnType(colTypes[i]));
+				ColumnType type = convertColumnType(colTypes[i]);
+				mColumnTypes.append(type);
+				if (type == Text || type == DiskStat)
+					mModel.addColumnAlignment(Qt::AlignLeft);
+				else
+					mModel.addColumnAlignment(Qt::AlignRight);
 			}
 			
 			mModel.setHorizontalHeaderLabels(translatedHeaders);
@@ -166,6 +175,20 @@
 					  case Time:
 						item->setData(QTime::fromString(records[j]), Qt::DisplayRole);
 						break;
+					  case KByte:
+						kbytes = records[j].toInt();
+						if(kbytes >= 1024*1024*1024*0.7) {  //If it's over 0.7TiB, then set the scale to terabytes
+							sbytes = kbytes / float(1024*1024*1024);
+							item->setText(i18nc("units", "%1 TiB", KGlobal::locale()->formatNumber(sbytes, sbytes < 9.9 ? 1 : 0)));
+						} else if(kbytes >= 1024*1024*0.7) { //If it's over 0.7GiB, then set the scale to gigabytes
+							sbytes = kbytes / float(1024*1024);
+							item->setText(i18nc("units", "%1 GiB", KGlobal::locale()->formatNumber(sbytes, sbytes < 9.9 ? 1 : 0)));
+						} else if(kbytes > 1024) {
+							sbytes = kbytes / float(1024);
+							item->setText(i18nc("units", "%1 MiB", KGlobal::locale()->formatNumber(sbytes, sbytes < 9.9 ? 1 : 0)));
+						} else
+							item->setText(i18nc("units", "%1 KiB", kbytes));
+						break;
 					  case DiskStat:
 					  case Text:
 					  default:
