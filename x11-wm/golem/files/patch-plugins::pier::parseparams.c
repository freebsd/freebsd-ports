--- plugins/pier/parseparams.c.old	Wed Aug  4 05:00:10 2004
+++ plugins/pier/parseparams.c	Wed Aug  4 05:00:25 2004
@@ -161,6 +161,7 @@
 			}
 			PWARN("ignoring unknown pier item type %s", itemparam->value);
 found:
+	continue;
 		}
 	}
 }
