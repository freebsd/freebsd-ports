--- src/uehandler.cc.orig	2003-09-12 19:06:06 UTC
+++ src/uehandler.cc
@@ -955,6 +955,7 @@ bool UEHandler::ExecCommand(Client *ref, Icon *i,char 
       if (!ExecAll)
         return false;
       {
+        lower(str);
         MenuInfo *mi = ((MenuInfo *)rman->GetInfo(SE_MENUINFO,str+1));
         if (mi) {
           int x,y;
