--- test/ipc_clients.c.orig	2026-09-29 16:05:39 UTC
+++ test/ipc_clients.c
@@ -43,6 +43,9 @@ int main(void) {
     /* Force EAGAIN and partial writes, then drain and verify the complete reply. */
     int size = 1024;
     CHECK(setsockopt(c.fd, SOL_SOCKET, SO_SNDBUF, &size, sizeof(size)) == 0);
+    /* BSD AF_UNIX stream sockets queue data in the receiver's buffer, so the
+     * sender's SO_SNDBUF alone does not force a partial write there. */
+    CHECK(setsockopt(pair[1], SOL_SOCKET, SO_RCVBUF, &size, sizeof(size)) == 0);
     char *line = malloc(OWE_IPC_MAX_LINE - 1);
     CHECK(line);
     memset(line, 'a', OWE_IPC_MAX_LINE - 2);
