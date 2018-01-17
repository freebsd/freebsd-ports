error: invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
    d->mUpdatesFile  = KGlobal::dirs()->locateLocal("cache", "kpc/"KDE_ICONCACHE_NAME".updated");
                                                                   ^
--- kdeui/icons/kiconcache.cpp.orig	2018-01-07 10:31:47 UTC
+++ kdeui/icons/kiconcache.cpp
@@ -103,7 +103,7 @@ class KIconCache::Private (public)
 KIconCache::KIconCache()
     : KPixmapCache(KDE_ICONCACHE_NAME), d(new Private(this))
 {
-    d->mUpdatesFile  = KGlobal::dirs()->locateLocal("cache", "kpc/"KDE_ICONCACHE_NAME".updated");
+    d->mUpdatesFile  = KGlobal::dirs()->locateLocal("cache", "kpc/" KDE_ICONCACHE_NAME ".updated");
     // Set limit to 10 MB
     setCacheLimit(10 * 1024);
 }
