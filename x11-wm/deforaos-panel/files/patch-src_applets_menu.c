--- src/applets/menu.c.orig	2023-10-28 13:53:50 UTC
+++ src/applets/menu.c
@@ -422,6 +422,8 @@ static void _menu_xdg_dirs(Menu * menu, void (*callbac
 #if defined(__NetBSD__)
 		/* XXX include the default path for pkgsrc */
 		path = "/usr/pkg/share:" DATADIR ":/usr/share";
+#elif defined(__FreeBSD__)
+		path = DATADIR ":/usr/share";
 #else
 		path = "/usr/local/share:" DATADIR ":/usr/share";
 #endif
