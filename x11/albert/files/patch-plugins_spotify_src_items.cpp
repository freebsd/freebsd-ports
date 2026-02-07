--- plugins/spotify/src/items.cpp.orig	2025-07-13 18:00:53 UTC
+++ plugins/spotify/src/items.cpp
@@ -24,7 +24,7 @@ static void pauseSpotify()
         !error.isEmpty())
         WARN << error;
 }
-#elif defined Q_OS_LINUX
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include <QDBusInterface>
 void pauseSpotify()
 {
@@ -35,6 +35,8 @@ void pauseSpotify()
         QDBusConnection::sessionBus()
     ).call(u"Pause"_s);
 }
+#else
+#   error "Unknown architecture"
 #endif
 
 SpotifyItem::SpotifyItem(RestApi &api,
