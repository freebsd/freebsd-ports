--- src/vte.c.orig	Tue Mar  4 14:25:26 2003
+++ src/vte.c	Wed Mar 26 01:42:42 2003
@@ -547,7 +547,7 @@
 static wchar_t
 vte_wc_from_unichar(VteTerminal *terminal, gunichar c)
 {
-#ifdef __STDC_ISO_10646__
+#if defined(__STDC_ISO_10646__) || (defined(__FreeBSD__) && __FreeBSD_version < 500000)
 	return (wchar_t) c;
 #else
 	gpointer original, result;
@@ -7320,7 +7320,7 @@
 	if (condition & G_IO_IN) {
 		bcount = sizeof(buf) -
 			 _vte_buffer_length(terminal->pvt->incoming);
-		bcount = read(fd, buf, MAX(bcount, sizeof(buf) / 2));
+		bcount = read(fd, buf, MAX(bcount, (int)(sizeof(buf) / 2)));
 	}
 	eof = FALSE;
 	if (condition & G_IO_HUP) {
