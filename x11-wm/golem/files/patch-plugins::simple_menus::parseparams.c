--- plugins/simple_menus/parseparams.c.orig	Wed Nov 28 01:44:35 2001
+++ plugins/simple_menus/parseparams.c	Wed Aug  4 04:58:14 2004
@@ -166,5 +166,6 @@
 		}
 		PWARN("ignoring unknown parameter type %s, under %s", param->name, topparam->name);
 found:
+	continue;
 	}
 }
