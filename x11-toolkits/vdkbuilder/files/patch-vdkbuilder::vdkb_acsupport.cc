--- vdkbuilder/vdkb_acsupport.cc.orig	Thu Feb 28 01:43:38 2002
+++ vdkbuilder/vdkb_acsupport.cc	Mon Nov 17 18:46:00 2003
@@ -106,7 +106,7 @@
 	;
       else
 	{
-	  sprintf(buff,"cp -a %s/res/%s %s/",
+	  sprintf(buff,"cp -pR %s/res/%s %s/",
 		  VDKB_DATADIR,
 		  tobecopied[t],
 		  (char*) tgtPath);
