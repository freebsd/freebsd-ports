From 6c1a7ca9176ff6924239c75f0ccdae7c3189b8bf Mon Sep 17 00:00:00 2001
From: Reginald Kennedy
Date: Fri, 19 Jun 2020 12:17:51 +0800
Subject: [PATCH] Fix always_raise.

---
 spectrwm.c | 14 +++++---------
 1 file changed, 5 insertions(+), 9 deletions(-)

diff --git a/spectrwm.c b/spectrwm.c
index b2632cc..49640d2 100644
--- spectrwm.c
+++ spectrwm.c
@@ -4824,9 +4824,8 @@ focus_win(struct ws_win *win)
 	win->focus_redirect = NULL; /* Clear any redirect from this window. */
 
 	if (ws->r) {
-		if (ws->cur_layout->flags & SWM_L_MAPONFOCUS ||
-		    ws->always_raise) {
-			/* Stack all related. */
+		if (ws->cur_layout->flags & SWM_L_MAPONFOCUS) {
+			/* Only related windows should be mapped. */
 			mainw = find_main_window(win);
 			TAILQ_FOREACH(w, &ws->stack, stack_entry) {
 				if (ICONIC(w))
@@ -4837,13 +4836,10 @@ focus_win(struct ws_win *win)
 				else
 					unmap_window(w);
 			}
-
 			update_stacking(win->s);
-		} else if (tile_gap < 0 && !FLOATING(win)) {
-			/*
-			 * Windows overlap in the layout.
-			 * Raise focused win above all tiled wins.
-			 */
+		} else if ((tile_gap < 0 && !FLOATING(win)) ||
+		    ws->always_raise) {
+			/* Focused window needs to be raised. */
 			raise_window(win);
 			update_win_stacking(win);
 			map_window(win);
