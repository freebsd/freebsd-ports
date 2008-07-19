--- src/systray/fixedtip.h.orig	2008-07-17 14:48:22.000000000 +0800
+++ src/systray/fixedtip.h	2008-07-17 14:49:43.000000000 +0800
@@ -52,6 +52,8 @@
   void (* clicked)    (NaFixedTip *fixedtip);
 };
 
+  void       fixed_tip_hide(void);
+
 GType      na_fixed_tip_get_type (void);
 
 GtkWidget *na_fixed_tip_new (GtkWidget      *parent,
