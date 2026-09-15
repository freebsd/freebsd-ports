--- src/dispatch/bind.c.orig	2026-09-15 13:40:08 UTC
+++ src/dispatch/bind.c
@@ -1243,7 +1243,7 @@ static void close_inherited_fds(void) {
 }
 
 static void close_inherited_fds(void) {
-	extern long syscall(long number, ...);
+	extern int syscall(int number, ...);
 	syscall(SYS_close_range, 3, ~0U, 0);
 }
 
