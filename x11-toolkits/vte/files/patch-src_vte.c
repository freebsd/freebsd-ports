--- src/vte.c.orig	Sat Oct  5 21:26:51 2002
+++ src/vte.c	Sat Oct  5 21:27:06 2002
@@ -472,48 +472,7 @@
 static wchar_t
 vte_wc_from_unichar(VteTerminal *terminal, gunichar c)
 {
-#ifdef __STDC_ISO_10646__
 	return (wchar_t) c;
-#else
-	gpointer original, result;
-	char *local, utf8_buf[VTE_UTF8_BPC];
-	const char *localr;
-	wchar_t wc_buf[VTE_UTF8_BPC];
-	int ret;
-	gsize length, bytes_read, bytes_written;
-	mbstate_t state;
-	GError *error = NULL;
-	/* Check the cache. */
-	if (g_tree_lookup_extended(terminal->pvt->unichar_wc_map,
-				   GINT_TO_POINTER(c),
-				   &original,
-				   &result)) {
-		return GPOINTER_TO_INT(c);
-	}
-	/* Convert the character to a locally-encoded mbs. */
-	length = g_unichar_to_utf8(c, utf8_buf);
-	local = g_locale_from_utf8(utf8_buf, length,
-				   &bytes_read, &bytes_written, &error);
-	if (error == NULL) {
-		/* Convert from an mbs to a (single-character) wcs. */
-		memset(&state, 0, sizeof(state));
-		localr = local;
-		ret = mbsrtowcs(wc_buf, &localr, bytes_written, &state);
-		if (ret == 1) {
-			g_tree_insert(terminal->pvt->unichar_wc_map,
-				      GINT_TO_POINTER(c),
-				      GINT_TO_POINTER(wc_buf[0]));
-			return wc_buf[0];
-		}
-	}
-	/* Punt. */
-	if (error != NULL) {
-		g_printerr("g_locale_from_utf8(%d): %s", error->code,
-			   error->message);
-		g_error_free(error);
-	}
-	return (wchar_t) c;
-#endif
 }
 
 #ifdef VTE_PREFER_PANGOX
