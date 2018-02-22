* Add the detailed setMemInfo used in ksysguard.cpp
*
--- ksysguard/gui/ksysguard.h.orig	2015-06-26 03:17:21 UTC
+++ ksysguard/gui/ksysguard.h
@@ -77,6 +77,7 @@ class TopLevel : public KXmlGuiWindow, p
     void configureCurrentSheet();
 
   private:
+    void setMemInfo( qlonglong, qlonglong, qlonglong, const QString& );
     void setSwapInfo( qlonglong, qlonglong, const QString& );
     void changeEvent( QEvent * event );
     void retranslateUi();
