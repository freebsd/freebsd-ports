
$FreeBSD$

--- src/options.c.orig
+++ src/options.c
@@ -3832,7 +3832,10 @@
     }
 #ifdef CUTCHAR_OPTION
     if (rs_cutchars) {
-        fprintf(fp, "    cut_chars '%s'\n", rs_cutchars);
+        spif_charptr_t cut_chars_escaped;
+
+        cut_chars_escaped = escape_string(SPIF_CAST(charptr) rs_cutchars, '\"', 0);
+        fprintf(fp, "    cut_chars \"%s\"\n", (char *) cut_chars_escaped);
     }
 #endif
     fprintf(fp, "end misc\n\n");
