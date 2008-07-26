
$FreeBSD$

--- gui/gdmchooser.c.orig
+++ gui/gdmchooser.c
@@ -727,7 +727,7 @@
 			/* paranoia */
 			ifreq.ifr_name[sizeof (ifreq.ifr_name) - 1] = '\0';
 
-			if (ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) 
+			if ((ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) && (errno != ENXIO))
 				gdm_common_error ("Could not get SIOCGIFFLAGS for %s", ifr[i].ifr_name);
 
 			if ((ifreq.ifr_flags & IFF_UP) == 0 ||
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
