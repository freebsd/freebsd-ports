From 6d7ab6669583816479d69dba6a83624ff9635392 Mon Sep 17 00:00:00 2001
From: Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
Date: Mon, 11 Jan 2021 21:17:51 +0100
Subject: [PATCH] clutter: Fix build with clang

Signed-off-by: Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
Part-of: <https://gitlab.gnome.org/GNOME/mutter/-/merge_requests/1668>
---
 clutter/clutter/cally/cally-text.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git clutter/clutter/cally/cally-text.c clutter/clutter/cally/cally-text.c
index 2b34f098..b6e8c8b7 100644
--- clutter/clutter/cally/cally-text.c
+++ clutter/clutter/cally/cally-text.c
@@ -1866,7 +1866,7 @@ static gint
 _cally_atk_attribute_lookup_func (gconstpointer data,
                                   gconstpointer user_data)
 {
-    AtkTextAttribute attr = (AtkTextAttribute) user_data;
+    AtkTextAttribute attr = (AtkTextAttribute) GPOINTER_TO_INT (user_data);
     AtkAttribute *at = (AtkAttribute *) data;
     if (!g_strcmp0 (at->name, atk_text_attribute_get_name (attr)))
         return 0;
-- 
2.37.0

