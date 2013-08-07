From c7eff39a5fb3552de57e52f737ea7ae59b1ef895 Mon Sep 17 00:00:00 2001
From: Michael Stapelberg <michael@stapelberg.de>
Date: Fri, 12 Jul 2013 17:57:44 +0000
Subject: don’t define xcb_cursor_context_t twice (Thanks Thomas)

This fixes a compilation problem on NetBSD
---
diff --git a/cursor/cursor.h b/cursor/cursor.h
index a69f025..7d8c76b 100644
--- cursor/cursor.h
+++ cursor/cursor.h
@@ -32,6 +32,8 @@
 #include <stdbool.h>
 #include <xcb/render.h>
 
+#include "xcb_cursor.h"
+
 enum {
     RM_XCURSOR_THEME = 0,
     RM_XCURSOR_SIZE,
@@ -61,7 +63,7 @@ typedef struct xcb_cursor_context_t {
     const char *path;
 
     bool render_present;
-} xcb_cursor_context_t;
+};
 
 /*
  * Cursor files start with a header.  The header
--
cgit v0.9.0.2-2-gbebe
