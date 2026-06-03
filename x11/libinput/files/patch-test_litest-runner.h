--- test/litest-runner.h.orig	2026-04-02 01:04:12 UTC
+++ test/litest-runner.h
@@ -198,3 +198,8 @@ litest_runner_abort(void);
  */
 __attribute__((noreturn)) void
 litest_runner_abort(void);
+
+static int get_nprocs(void)
+{
+	return sysconf (_SC_NPROCESSORS_ONLN);
+}
