--- ../treewm-0.4.5.orig/src/uehandler.cc	Mon Mar  8 00:20:42 2004
+++ src/uehandler.cc	Mon Mar  8 00:42:26 2004
@@ -955,6 +955,7 @@
       if (!ExecAll)
         return false;
       {
+        lower(str);
         MenuInfo *mi = ((MenuInfo *)rman->GetInfo(SE_MENUINFO,str+1));
         if (mi) {
           int x,y;
