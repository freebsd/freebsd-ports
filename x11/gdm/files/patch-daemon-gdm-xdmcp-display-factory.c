--- daemon/gdm-xdmcp-display-factory.c.orig	2009-07-20 03:09:09.000000000 +0200
+++ daemon/gdm-xdmcp-display-factory.c	2009-07-20 09:54:25.000000000 +0200
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
@@ -835,7 +851,7 @@ gdm_xdmcp_send_willing (GdmXdmcpDisplayF
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         g_free (status.data);
 }
@@ -879,7 +895,7 @@ gdm_xdmcp_send_unwilling (GdmXdmcpDispla
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         last_time = time (NULL);
 }
@@ -988,7 +1004,7 @@ gdm_xdmcp_send_forward_query (GdmXdmcpDi
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (ic->chosen_address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (ic->chosen_address)));
 
         g_free (port.data);
         g_free (addr.data);
@@ -1691,7 +1707,7 @@ gdm_xdmcp_really_send_managed_forward (G
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         g_free (addr.data);
 }
@@ -1772,7 +1788,7 @@ gdm_xdmcp_send_got_managed_forward (GdmX
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static gboolean
@@ -1945,7 +1961,7 @@ gdm_xdmcp_send_decline (GdmXdmcpDisplayF
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         /* Send MANAGED_FORWARD to indicate that the connection
          * reached some sort of resolution */
@@ -2093,7 +2109,7 @@ gdm_xdmcp_send_accept (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         host = NULL;
         gdm_address_get_numeric_info (address, &host, NULL);
@@ -2424,7 +2440,7 @@ gdm_xdmcp_send_failed (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static void
@@ -2448,7 +2464,7 @@ gdm_xdmcp_send_refuse (GdmXdmcpDisplayFa
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 
         /*
          * This was from a forwarded query quite apparently so
@@ -2719,7 +2735,7 @@ gdm_xdmcp_send_alive (GdmXdmcpDisplayFac
         XdmcpFlush (factory->priv->socket_fd,
                     &factory->priv->buf,
                     (XdmcpNetaddr)gdm_address_peek_sockaddr_storage (address),
-                    (int)sizeof (struct sockaddr_storage));
+                    (int)gdm_sockaddr_len (gdm_address_peek_sockaddr_storage (address)));
 }
 
 static void
