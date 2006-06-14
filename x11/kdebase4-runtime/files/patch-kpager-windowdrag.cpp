--- kpager/windowdrag.cpp	2006/05/23 12:51:36	544025
+++ kpager/windowdrag.cpp	2006/06/05 19:55:59	548525
@@ -31,7 +31,7 @@
     QString tmp;
     tmp.sprintf("%d %d %d %d", static_cast<int>(w), deltax, deltay, origdesk);
     QByteArray data(tmp.length()+1);
-    data.assign(tmp.latin1(),tmp.length()+1);
+    data.duplicate(tmp.latin1(),tmp.length()+1);
 
     setEncodedData(data);
 }
