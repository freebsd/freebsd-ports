From 765c984f680469f32cd30fe5cea63fa3af6fc1df Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Ga=C3=ABl=20Bonithon?= <gael@xfce.org>
Date: Fri, 20 Mar 2026 12:02:17 +0100
Subject: [PATCH] Be sure to handle primary paste ourselves

Fixes: #385
Amends: fd3bd9b02d81b19e10e4f9a68ff9c0dc19d06804
---
 terminal/terminal-widget.c | 12 +++++++++++-
 1 file changed, 11 insertions(+), 1 deletion(-)

diff --git a/terminal/terminal-widget.c b/terminal/terminal-widget.c
index 6c0f97b8..46756688 100644
--- terminal/terminal-widget.c
+++ terminal/terminal-widget.c
@@ -609,7 +609,17 @@ terminal_widget_button_press_event (GtkWidget *widget,
     }
 
   if (!intercept)
-    handled = (*GTK_WIDGET_CLASS (terminal_widget_parent_class)->button_press_event) (widget, event);
+    {
+      GtkSettings *settings = gtk_settings_get_default ();
+      gboolean primary_paste_enabled;
+      g_object_get (settings, "gtk-enable-primary-paste", &primary_paste_enabled, NULL);
+
+      /* don't let vte handle primary paste; we want to do it ourselves later, especially
+       * to trigger the unsafe paste dialog if necessary */
+      g_object_set (settings, "gtk-enable-primary-paste", FALSE, NULL);
+      handled = (*GTK_WIDGET_CLASS (terminal_widget_parent_class)->button_press_event) (widget, event);
+      g_object_set (settings, "gtk-enable-primary-paste", primary_paste_enabled, NULL);
+    }
 
   if (event->button == 2 && event->type == GDK_BUTTON_PRESS)
     {
-- 
GitLab

