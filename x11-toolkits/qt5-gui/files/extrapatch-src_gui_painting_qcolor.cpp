On FreeBSD 9.3 with gcc-4.2 we need to mark the constant as an unsigned long long. 
Else the compiler will choke on it being too large:

c++ -c -O2 -pipe [...] itemmodels/qstandarditemmodel.cpp
painting/qcolor.cpp:527: error: integer constant is too large for 'long' type
*** [.obj/qcolor.o] Error code 1
1 error


--- src/gui/painting/qcolor.cpp.orig	2016-10-10 16:17:59 UTC
+++ src/gui/painting/qcolor.cpp
@@ -524,7 +524,7 @@ QString QColor::name(NameFormat format) 
         return QLatin1Char('#') + QString::number(rgba() | 0x1000000, 16).rightRef(6);
     case HexArgb:
         // it's called rgba() but it does return AARRGGBB
-        return QLatin1Char('#') + QString::number(rgba() | 0x100000000, 16).rightRef(8);
+        return QLatin1Char('#') + QString::number(rgba() | 0x100000000ULL, 16).rightRef(8);
     }
     return QString();
 }
