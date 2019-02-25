From dc04e969dd61a2b1f82beae2d3c8ad105447812d Mon Sep 17 00:00:00 2001
From: Leigh Scott <leigh123linux@googlemail.com>
Date: Wed, 6 Feb 2019 01:04:17 +0000
Subject: [PATCH] rename g_strv_equal to matekbd_strv_equal

---
 libmatekbd/matekbd-keyboard-config.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/libmatekbd/matekbd-keyboard-config.c b/libmatekbd/matekbd-keyboard-config.c
index 4c9db11..40b4022 100644
--- libmatekbd/matekbd-keyboard-config.c
+++ libmatekbd/matekbd-keyboard-config.c
@@ -53,7 +53,7 @@ const gchar *MATEKBD_KEYBOARD_CONFIG_ACTIVE[] = {
  */
 
 static gboolean
-g_strv_equal (gchar ** l1, gchar ** l2)
+matekbd_strv_equal (gchar ** l1, gchar ** l2)
 {
 	if (l1 == l2)
 		return TRUE;
@@ -555,7 +555,7 @@ matekbd_keyboard_config_equals (MatekbdKeyboardConfig * kbd_config1,
 	    (kbd_config2->model != NULL) &&
 	    g_ascii_strcasecmp (kbd_config1->model, kbd_config2->model))
 		return False;
-	if (!g_strv_equal (kbd_config1->layouts_variants,
+	if (!matekbd_strv_equal (kbd_config1->layouts_variants,
 			   kbd_config2->layouts_variants))
 		return False;
 
