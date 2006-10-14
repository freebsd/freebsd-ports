--- libxklavier/xklavier_config.c	2006-04-15 22:04:38.000000000 -0400
+++ libxklavier/xklavier_config.c	2006-07-08 10:15:17.000000000 -0400
@@ -275,7 +275,11 @@
 gchar *
 xkl_strings_concat_comma_separated(gchar ** array)
 {
-	return g_strjoinv(",", array);
+	if (array) {
+		return g_strjoinv(",", array);
+	} else {
+		return g_strdup("");
+	}
 }
 
 void
