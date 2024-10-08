# Official fixes for 32-bit compilation
--- src/vblank.c.orig	2024-09-28 23:22:13 UTC
+++ src/vblank.c
@@ -409,7 +409,7 @@ static void handle_present_complete_notify(struct pres
 
 	struct timespec now;
 	clock_gettime(CLOCK_MONOTONIC, &now);
-	auto now_us = (unsigned long)(now.tv_sec * 1000000L + now.tv_nsec / 1000);
+	auto now_us = (uint64_t)now.tv_sec * 1000000UL + (uint64_t)now.tv_nsec / 1000;
 
 	// X sometimes sends duplicate/bogus MSC events, when screen has just been turned
 	// off. Don't use the msc value in these events. We treat this as not receiving a
