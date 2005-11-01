--- mod_statusbar/ion-statusd/ion-statusd.c	Sat Oct 29 14:33:05 2005
+++ mod_statusbar/ion-statusd/ion-statusd.c	Mon Oct 31 20:29:09 2005
@@ -143,8 +143,10 @@
     int opt;
     bool quiet=FALSE;
 
+#if !defined (CF_NO_LOCALE)
     if(setlocale(LC_ALL, "")==NULL)
         warn("setlocale() call failed.");
+#endif
 
     configtab=extl_table_none();
     
