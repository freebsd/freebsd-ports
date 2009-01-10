--- gui/simple-chooser/gdm-host-chooser-widget.c.orig	2008-03-04 14:42:37.000000000 -0500
+++ gui/simple-chooser/gdm-host-chooser-widget.c	2008-08-03 01:48:49.000000000 -0400
@@ -442,7 +442,7 @@ find_broadcast_addresses (GdmHostChooser
                         /* paranoia */
                         ifreq.ifr_name[sizeof (ifreq.ifr_name) - 1] = '\0';
 
-                        if (ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) {
+                        if ((ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) && (errno != ENXIO)) {
                                 g_warning ("Could not get SIOCGIFFLAGS for %s", ifr[i].ifr_name);
                         }
 
@@ -542,6 +542,8 @@ xdmcp_init (GdmHostChooserWidget *widget
 #ifdef ENABLE_IPV6
         widget->priv->socket_fd = socket (AF_INET6, SOCK_DGRAM, 0);
         if (widget->priv->socket_fd != -1) {
+                int no = 0;
+                setsockopt(widget->priv->socket_fd, IPPROTO_IPV6, IPV6_V6ONLY, &no, sizeof(no));
                 widget->priv->have_ipv6 = TRUE;
         }
 #endif
