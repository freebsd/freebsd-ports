From 8392fc4769466700fc9644c734ad5b010be28655 Mon Sep 17 00:00:00 2001
From: "Carsten Haitzler (Rasterman)" <raster@rasterman.com>
Date: Sun, 10 May 2020 18:11:43 +0100
Subject: emix - fix symbols to point to correct extern sym

---
 src/modules/mixer/lib/emix.c | 8 ++++----
 1 file changed, 4 insertions(+), 4 deletions(-)

(limited to 'src/modules/mixer/lib/emix.c')

diff --git a/src/modules/mixer/lib/emix.c b/src/modules/mixer/lib/emix.c
index 65f9cb33f..cb8ea128b 100644
--- src/modules/mixer/lib/emix.c
+++ src/modules/mixer/lib/emix.c
@@ -5,12 +5,12 @@
 #include "emix.h"
 
 #ifdef HAVE_PULSE
-E_API Emix_Backend *emix_backend_pulse_get(void);
-E_API const char    *emix_backend_pulse_name;
+E_API Emix_Backend      *emix_backend_pulse_get(void);
+E_API extern const char *emix_backend_pulse_name;
 #endif
 #ifdef HAVE_ALSA
-E_API Emix_Backend *emix_backend_alsa_get(void);
-E_API const char    *emix_backend_alsa_name;
+E_API Emix_Backend      *emix_backend_alsa_get(void);
+E_API extern const char *emix_backend_alsa_name;
 #endif
 
 static int _log_domain;
-- 
cgit v1.2.1

