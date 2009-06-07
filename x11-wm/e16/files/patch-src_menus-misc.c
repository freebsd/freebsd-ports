--- src/menus-misc.c.orig	2009-06-08 00:30:15.000000000 +0200
+++ src/menus-misc.c	2009-06-08 00:32:24.000000000 +0200
@@ -255,6 +255,16 @@
    menu_scan_recursive = 0;
 }
 
+static char *
+find_icon(const char *file)
+{
+    char s[FILEPATH_LEN_MAX];
+
+    Esnprintf(s, sizeof(s), "%s/icons", EDirUser());
+
+    return FindFile(file, s);
+}
+
 static void
 FillFlatFileMenu(Menu * m, const char *file)
 {
@@ -311,12 +321,13 @@
 	     txt = icon = act = params = NULL;
 	     parse(s, "%S%T%S%S", &txt, &icon, &act, &params);
 
-	     if (icon && exists(icon))
+	     if (icon && (icon = find_icon(icon)))
 	       {
 		  Esnprintf(wd, sizeof(wd), "__FM.%s", icon);
 		  icc = ImageclassFind(wd, 0);
 		  if (!icc)
 		     icc = ImageclassCreateSimple(wd, icon);
+		  Efree(icon);
 	       }
 	     if ((act) && (!strcmp(act, "exec")) && (params))
 	       {
