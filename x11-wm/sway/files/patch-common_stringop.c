https://github.com/swaywm/sway/issues/8673#issuecomment-2818260191

--- common/stringop.c.orig	2025-04-20 11:31:10 UTC
+++ common/stringop.c
@@ -6,6 +6,8 @@
 #include <string.h>
 #include <strings.h>
 #include <wordexp.h>
+#include <signal.h>
+#include <sys/wait.h>
 #include "list.h"
 #include "log.h"
 #include "stringop.h"
@@ -318,11 +320,34 @@ bool expand_path(char **path) {
 		char *ptr = strstr(*path, "  ") + 1;
 		memmove(ptr + 1, ptr, strlen(ptr) + 1);
 		*ptr = '\\';
-	}
-	if (wordexp(*path, &p, 0) != 0 || p.we_wordv[0] == NULL) {
-		wordfree(&p);
-		return false;
-	}
+       }
+
+       // FreeBSD wordexp bug workaround:
+       // 1. Reset SIGCHLD handler
+       // 2. Run wordexp
+       // 3. Restore SIGCHLD handler and reap any processes that exited
+       struct sigaction prev_action;
+       struct sigaction new_action = {
+               .sa_flags = SA_RESETHAND,
+       };
+       if (sigaction(SIGCHLD, &new_action, &prev_action) != 0) {
+               sway_log(SWAY_ERROR, "Restoring sigchild before wordexp failed");
+               return false;
+       }
+
+       int res = wordexp(*path, &p, 0);
+
+       if (sigaction(SIGCHLD, &prev_action, NULL) != 0) {
+               sway_log(SWAY_ERROR, "Restoring sigchild after wordexp failed");
+       }
+
+       int status;
+       while (waitpid(-1, &status, WNOHANG) != -1 || errno == EINTR);
+
+       if (res != 0 || p.we_wordv[0] == NULL) {
+               wordfree(&p);
+               return false;
+       }
 	free(*path);
 	*path = join_args(p.we_wordv, p.we_wordc);
 	wordfree(&p);
