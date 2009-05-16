--- daemon/gdm-xdmcp-display-factory.c.orig	2009-03-16 16:12:08.000000000 -0400
+++ daemon/gdm-xdmcp-display-factory.c	2009-05-16 18:17:26.000000000 -0400
@@ -35,6 +35,7 @@
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <netinet/in.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
@@ -76,7 +77,7 @@ int deny_severity = LOG_WARNING;
 #define DEFAULT_USE_MULTICAST         FALSE
 #define DEFAULT_MULTICAST_ADDRESS     "ff02::1"
 #define DEFAULT_HONOR_INDIRECT        TRUE
-#define DEFAULT_MAX_DISPLAYS_PER_HOST 1
+#define DEFAULT_MAX_DISPLAYS_PER_HOST 2
 #define DEFAULT_MAX_DISPLAYS          16
 #define DEFAULT_MAX_PENDING_DISPLAYS  4
 #define DEFAULT_MAX_WAIT              30
@@ -404,6 +405,11 @@ static int
 create_socket (struct addrinfo *ai)
 {
         int sock;
+#ifdef ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+	int off = 0;
+#endif
+#endif
 
         sock = socket (ai->ai_family, ai->ai_socktype, ai->ai_protocol);
         if (sock < 0) {
@@ -411,6 +417,16 @@ create_socket (struct addrinfo *ai)
                 return sock;
         }
 
+#ifdef ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+	if (setsockopt (sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof (off)) < 0) {
+		g_warning ("setsockopt: %s", g_strerror (errno));
+		close (sock);
+		return -1;
+	}
+#endif
+#endif
+
         if (bind (sock, ai->ai_addr, ai->ai_addrlen) < 0) {
                 g_warning ("bind: %s", g_strerror (errno));
                 close (sock);
@@ -833,7 +849,7 @@ gdm_xdmcp_send_willing (GdmXdmcpDisplayF
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         g_free (status.data);
 }
@@ -877,7 +893,7 @@ gdm_xdmcp_send_unwilling (GdmXdmcpDispla
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         last_time = time (NULL);
 }
@@ -986,7 +1002,7 @@ gdm_xdmcp_send_forward_query (GdmXdmcpDi
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (ic->chosen_address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (ic->chosen_address)));
 
         g_free (port.data);
         g_free (addr.data);
@@ -1689,7 +1705,7 @@ gdm_xdmcp_really_send_managed_forward (G
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         g_free (addr.data);
 }
@@ -1770,7 +1786,7 @@ gdm_xdmcp_send_got_managed_forward (GdmX
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static gboolean
@@ -1943,7 +1959,7 @@ gdm_xdmcp_send_decline (GdmXdmcpDisplayF
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         /* Send MANAGED_FORWARD to indicate that the connection
          * reached some sort of resolution */
@@ -2091,7 +2107,7 @@ gdm_xdmcp_send_accept (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         host = NULL;
         gdm_address_get_numeric_info (address, &host, NULL);
@@ -2309,8 +2325,6 @@ gdm_xdmcp_handle_request (GdmXdmcpDispla
                                 authorization_data.data     = (CARD8 *) cookie->data;
                                 authorization_data.length   = cookie->len;
 
-                                g_array_free (cookie, TRUE);
-
                                 /* the addrs are NOT copied */
                                 gdm_xdmcp_send_accept (factory,
                                                        address,
@@ -2319,6 +2333,8 @@ gdm_xdmcp_handle_request (GdmXdmcpDispla
                                                        &authentication_data,
                                                        &authorization_name,
                                                        &authorization_data);
+
+                                g_array_free (cookie, TRUE);
                         }
                 }
         } else {
@@ -2422,7 +2438,7 @@ gdm_xdmcp_send_failed (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static void
@@ -2446,7 +2462,7 @@ gdm_xdmcp_send_refuse (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         /*
          * This was from a forwarded query quite apparently so
@@ -2717,7 +2733,7 @@ gdm_xdmcp_send_alive (GdmXdmcpDisplayFac
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static void
