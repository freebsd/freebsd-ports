
$FreeBSD$

--- include/wx/gtk/menu.h	2002/09/09 11:38:53	1.1
+++ include/wx/gtk/menu.h	2002/09/09 11:39:09
@@ -85,7 +85,9 @@
     {
         Init();
 
+#if wxUSE_MENU_CALLBACK
         Callback(func);
+#endif // wxUSE_MENU_CALLBACK
     }
 
     // implementation
