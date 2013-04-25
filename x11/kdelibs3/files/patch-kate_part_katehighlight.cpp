The earlier g++ tolerated this, but g++48 does not...
With this patch kdelibs3 can be compiled with the latest compiler.

	-mi

--- kate/part/katehighlight.cpp	2007-05-14 03:52:27.000000000 -0400
+++ kate/part/katehighlight.cpp	2013-04-24 20:37:19.000000000 -0400
@@ -3226,5 +3226,5 @@
 
   KateAttribute* string = new KateAttribute();
-  string->setTextColor(QColor::QColor("#D00"));
+  string->setTextColor(QColor("#D00"));
   string->setSelectedTextColor(Qt::red);
   list.append(string);
@@ -3243,7 +3243,7 @@
   KateAttribute* alert = new KateAttribute();
   alert->setTextColor(Qt::black);
-  alert->setSelectedTextColor( QColor::QColor("#FCC") );
+  alert->setSelectedTextColor( QColor("#FCC") );
   alert->setBold(true);
-  alert->setBGColor( QColor::QColor("#FCC") );
+  alert->setBGColor( QColor("#FCC") );
   list.append(alert);
 
