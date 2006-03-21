
$FreeBSD$

--- src/misc.c.orig
+++ src/misc.c
@@ -223,6 +223,53 @@
     return (pnew - str);
 }
 
+spif_charptr_t
+escape_string(spif_charptr_t str, spif_char_t quote, spif_int32_t maxlen)
+{
+    spif_charptr_t buff, s = str, pbuff;
+
+    D_STRINGS(("escape_string(%s %c %ld)\n", (char *) str, quote, maxlen));
+    if (! quote) {
+        quote = '\"';
+    }
+
+    /* The escaped string will be at most twice the length of the original. */
+    buff = SPIF_CAST(charptr) MALLOC(strlen(SPIF_CAST_PTR(char) str) * 2 + 1);
+
+    /* Copy and escape the string from str into buff. */
+    for (pbuff = buff; (*s); s++, pbuff++) {
+        if (*s == quote) {
+            D_STRINGS(("Double-escaping \'%c\' at position %d\n", *s, s - str));
+            *pbuff = '\\';
+            pbuff++;
+            *pbuff = '\\';
+            pbuff++;
+        } else {
+            if (quote == '\"') {
+                if ((*s == '\\') || (*s == '`')) {
+                    D_STRINGS(("Escaping \'%c\' at position %d\n", *s, s - str));
+                    *pbuff = '\\';
+                    pbuff++;
+                }
+            }
+        }
+        D_STRINGS(("Copying \'%c\' at position %d\n", *s, s - str));
+        *pbuff = *s;
+    }
+    *pbuff = 0;
+
+    if (maxlen) {
+        /* Given maxlen, we know "str" can hold at least "maxlen" chars. */
+        if (!spiftool_safe_strncpy(str, buff, maxlen)) {
+            str[maxlen] = 0;
+        }
+        FREE(buff);
+        return str;
+    } else {
+        return buff;
+    }
+}
+
 char *
 safe_print_string(const char *str, unsigned long len)
 {
