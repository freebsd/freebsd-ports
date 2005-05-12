--- daemon/gdm-net.c.orig	Thu May 12 01:00:31 2005
+++ daemon/gdm-net.c	Thu May 12 01:00:36 2005
@@ -76,14 +76,14 @@ struct _GdmConnection {
 };
 
 static gboolean
-close_if_needed (GdmConnection *conn, GIOCondition cond)
+close_if_needed (GdmConnection *conn, GIOCondition cond, gboolean error)
 {
 	/* non-subconnections are never closed */
 	if (conn->parent == NULL)
 		return TRUE;
 
 	if (cond & G_IO_ERR ||
-	    cond & G_IO_HUP) {
+	    cond & G_IO_HUP || error) {
 		gdm_debug ("close_if_needed: Got HUP/ERR on %d", conn->fd);
 		conn->source = 0;
 		gdm_connection_close (conn);
@@ -103,11 +103,11 @@ gdm_connection_handler (GIOChannel *sour
 	size_t len;
 
 	if ( ! (cond & G_IO_IN)) 
-		return close_if_needed (conn, cond);
+		return close_if_needed (conn, cond, FALSE);
 
 	VE_IGNORE_EINTR (len = read (conn->fd, buf, sizeof (buf) -1));
 	if (len <= 0) {
-		return close_if_needed (conn, cond);
+		return close_if_needed (conn, cond, TRUE);
 	}
 
 	buf[len] = '\0';
@@ -141,7 +141,7 @@ gdm_connection_handler (GIOChannel *sour
 		}
 	}
 
-	return close_if_needed (conn, cond);
+	return close_if_needed (conn, cond, FALSE);
 }
 
 gboolean
