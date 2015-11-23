From 746b5b64a6daa660dfc65f531f0cd46628c13660 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?=C3=98yvind=20Kol=C3=A5s?= <pippin@gimp.org>
Date: Sat, 21 Nov 2015 03:44:13 +0100
Subject: fix bug 755405

---
 extensions/gggl.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/extensions/gggl.c b/extensions/gggl.c
index e9fc1d9..7b05e12 100644
--- extensions/gggl.c
+++ extensions/gggl.c
@@ -673,7 +673,7 @@ conv_rgbF_rgbaF (unsigned char *src, unsigned char *dst, long samples)
       *(uint32_t *) dst = (*(uint32_t *) src);
       src           += 4;
       dst           += 4;
-      *(uint32_t *) dst = 1.0;
+      *(float *) dst = 1.0;
       dst           += 4;
     }
   return samples;
-- 
cgit v0.11.2

