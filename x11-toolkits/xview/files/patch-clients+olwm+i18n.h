--- ./clients/olwm/i18n.h.orig	Tue Jun 29 07:11:48 1993
+++ ./clients/olwm/i18n.h	Sat Apr  1 18:26:06 2000
@@ -35,6 +35,10 @@ extern wchar_t  *mbstowcsdup();
 
 #endif /* OW_I18N_L4 */
 
+#ifndef LC_MESSAGES
+#define LC_MESSAGES 0
+#endif
+
 /*
  *	String/Text - To better handle non-i18n, Level3 and Level4
  *	we introduce two 'types'; string and text.
