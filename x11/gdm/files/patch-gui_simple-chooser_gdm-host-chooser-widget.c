--- gui/simple-chooser/gdm-host-chooser-widget.c.orig	2010-01-13 14:29:00.000000000 +0000
+++ gui/simple-chooser/gdm-host-chooser-widget.c	2010-01-17 13:04:14.000000000 +0000
@@ -543,6 +543,8 @@ xdmcp_init (GdmHostChooserWidget *widget
 #ifdef ENABLE_IPV6
         widget->priv->socket_fd = socket (AF_INET6, SOCK_DGRAM, 0);
         if (widget->priv->socket_fd != -1) {
+		int off = 0;
+		setsockopt(widget->priv->socket_fd, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof (off));
                 widget->priv->have_ipv6 = TRUE;
         }
 #endif
