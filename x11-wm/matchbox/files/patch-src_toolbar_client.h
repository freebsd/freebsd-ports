$FreeBSD$

--- src/toolbar_client.h.orig	Wed Feb 13 17:04:26 2002
+++ src/toolbar_client.h	Wed Sep 25 13:23:32 2002
@@ -42,4 +42,4 @@ void toolbar_client_reparent(Client *c);
 void toolbar_client_redraw(Client *c, Bool use_cache);
 int toolbar_win_offset(Client *c);
 
-#endif _TOOLBAR_CLIENT_H_
+#endif /* _TOOLBAR_CLIENT_H_ */
