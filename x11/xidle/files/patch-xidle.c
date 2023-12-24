--- xidle.c.orig	2023-12-17 16:06:14 UTC
+++ xidle.c
@@ -426,7 +426,7 @@ main(int argc, char **argv)
 				 * Was for real or due to terminal
 				 * switching or a locking program?
 				 */
-				if (timeout > 0 && se->forced == False)
+				if (timeout > 0 && se->forced == False && se->state == ScreenSaverOn)
 					action(&x, args);
 			}
 			break;
