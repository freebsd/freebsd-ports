--- kcms/region_language/kcmregionandlang.cpp.orig	2023-02-28 12:23:29 UTC
+++ kcms/region_language/kcmregionandlang.cpp
@@ -77,9 +77,8 @@ KCMRegionAndLang::KCMRegionAndLang(QObject *parent, co
             });
             m_localectl->start();
         }
-    } else {
-        m_enabled = true;
     }
+    m_enabled = true;
 }
 
 QString KCMRegionAndLang::failedFindLocalesMessage()
