--- ../treewm-0.4.5.orig/src/resmanager.cc	Mon Mar  8 00:20:42 2004
+++ src/resmanager.cc	Mon Mar  8 00:40:02 2004
@@ -127,6 +127,7 @@
     for (int j=0; j!=mi->n; ++j) {
       MenuItem &mitem = mi->menu[j];
       if (mitem.key[0] == '$') {
+        lower(mitem.key);
         MenuInfo *mi2 = (MenuInfo *)rman->GetInfo(SE_MENUINFO,mitem.key+1);
         if (mi2) {
           mitem.submenu = new SubMenuInfo;
