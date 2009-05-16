--- gui/simple-chooser/gdm-host-chooser-widget.c.orig	2009-02-19 21:45:09.000000000 -0500
+++ gui/simple-chooser/gdm-host-chooser-widget.c	2009-05-11 02:34:20.000000000 -0400
@@ -311,7 +311,7 @@ do_ping (GdmHostChooserWidget *widget,
                 res = XdmcpFlush (widget->priv->socket_fd,
                                   &widget->priv->broadcast_buf,
                                   (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                                  (int)sizeof (struct sockaddr_storage));
+                                  (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
                 if (! res) {
                         g_warning ("Unable to flush the XDMCP broadcast packet: %s", g_strerror (errno));
                 }
@@ -328,7 +328,7 @@ do_ping (GdmHostChooserWidget *widget,
                         res = XdmcpFlush (widget->priv->socket_fd,
                                           &widget->priv->query_buf,
                                           (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                                          (int)sizeof (struct sockaddr_storage));
+                                          (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
                         if (! res) {
                                 g_warning ("Unable to flush the XDMCP query packet");
                         }
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
+                int off = 0;
+                setsockopt(widget->priv->socket_fd, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof (off));
                 widget->priv->have_ipv6 = TRUE;
         }
 #endif
