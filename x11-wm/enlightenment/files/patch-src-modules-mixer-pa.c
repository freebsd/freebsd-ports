--- src/modules/mixer/pa.c.orig	2012-04-01 23:52:05.418578586 +0200
+++ src/modules/mixer/pa.c	2012-04-01 23:52:28.819577346 +0200
@@ -350,7 +350,6 @@
    INF("connected to %s", ecore_con_server_name_get(ev->server));
 
    conn->fd = dup(ecore_con_server_fd_get(ev->server));
-   setsockopt(conn->fd, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on));
    setsockopt(conn->fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    fcntl(conn->fd, F_SETFL, O_NONBLOCK | FD_CLOEXEC);
    conn->fdh = ecore_main_fd_handler_add(conn->fd, ECORE_FD_WRITE, (Ecore_Fd_Cb)fdh_func, conn, NULL, NULL);
