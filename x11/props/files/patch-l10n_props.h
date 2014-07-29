--- l10n_props.h.orig	Tue Nov  4 20:36:07 1997
+++ l10n_props.h	Tue Nov  4 20:36:31 1997
@@ -13,6 +13,9 @@
  */
 #define	LOCALE_NAME_LEN		20
 
+#ifndef LC_MESSAGES
+#define LC_MESSAGES 0
+#endif
 
 typedef struct	_l10n_config_list_item {
 	/*
