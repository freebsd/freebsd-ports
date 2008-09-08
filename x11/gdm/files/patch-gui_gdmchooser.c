
$FreeBSD$

--- gui/gdmchooser.c.orig
+++ gui/gdmchooser.c
@@ -1123,6 +1123,12 @@
 		have_ipv6 = FALSE;
 	else
 		have_ipv6 = TRUE;
+	/* Net- & FreeBSD default to V6ONLY */
+	{
+		int no = 0;
+		setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &no, sizeof(no));
+	}
+
 #endif
 	if ( ! have_ipv6) {
 		if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) == -1) {
