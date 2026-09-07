--- src/dispatch/bind_define.h.orig	2026-09-04 03:02:04 UTC
+++ src/dispatch/bind_define.h
@@ -1111,7 +1111,7 @@ static void close_inherited_fds(void) {
 
 static void close_inherited_fds(void) {
 #ifdef SYS_close_range
-	extern long syscall(long number, ...);
+	extern int syscall(int number, ...);
 	if (syscall(SYS_close_range, 3, ~0U, 0) == 0)
 		return;
 #endif
