--- src/resmanager.cc.orig	2003-02-15 21:05:41 UTC
+++ src/resmanager.cc
@@ -127,6 +127,7 @@ void ResManager::CreateScemes() {
     for (int j=0; j!=mi->n; ++j) {
       MenuItem &mitem = mi->menu[j];
       if (mitem.key[0] == '$') {
+        lower(mitem.key);
         MenuInfo *mi2 = (MenuInfo *)rman->GetInfo(SE_MENUINFO,mitem.key+1);
         if (mi2) {
           mitem.submenu = new SubMenuInfo;
