commit e7951201a19a4439b6ad95440c6de9b6b3620e45
Author: Aaron Seigo <aseigo@kde.org>
Date:   Fri May 6 15:19:09 2011 +0200

    use a QWeakPointer on the KIconLoader passed in as there are no lifetime guarantees
    
    usually KGlobal::iconLoader() is used, so this isn't an issue seen very often.
    however, when a local KIconLoader is created, it is easy to get QIcons with a
    KIconEngine that has a bad KIconLoader pointer in them. particularly as QIcon
    is implicitly shared and easily passed around. the StatusNotifier Plasma DataEngine
    was triggering this, though it would be trivial to run into this problem again
    anytime a KIconLoader is created locally
    
    thankfully, QWeakPointer does the job and is very fast and light. (confirmed
    both with my own testing and confirmation from Thiago).
    
    massive thanks to Michael Pyne for detecting the cause of the problem via Valgrind.
    
    BUG:258706

--- kdeui/icons/kiconengine.cpp
+++ kdeui/icons/kiconengine.cpp
@@ -27,16 +27,16 @@
 
 
 KIconEngine::KIconEngine(const QString& iconName, KIconLoader* iconLoader, const QStringList& overlays)
+    : mIconName(iconName),
+      mIconLoader(iconLoader),
+      mOverlays(overlays)
 {
-    mIconName = iconName;
-    mIconLoader = iconLoader;
-    mOverlays = overlays;
 }
 
 KIconEngine::KIconEngine(const QString& iconName, KIconLoader* iconLoader)
+    : mIconName(iconName),
+      mIconLoader(iconLoader)
 {
-    mIconName = iconName;
-    mIconLoader = iconLoader;
 }
 
 static inline int qIconModeToKIconState( QIcon::Mode mode )
@@ -65,8 +65,12 @@ QSize KIconEngine::actualSize( const QSize & size, QIcon::Mode mode, QIcon::Stat
     return QSize(iconSize, iconSize);
 }
 
-void KIconEngine::paint( QPainter * painter, const QRect & rect, QIcon::Mode mode, QIcon::State state )
+void KIconEngine::paint(QPainter * painter, const QRect & rect, QIcon::Mode mode, QIcon::State state)
 {
+    if (!mIconLoader) {
+        return;
+    }
+
     Q_UNUSED(state)
 
     const int kstate = qIconModeToKIconState(mode);
@@ -80,20 +84,27 @@ void KIconEngine::paint( QPainter * painter, const QRect & rect, QIcon::Mode mod
     }
 
     const int iconSize = qMin(rect.width(), rect.height());
-    const QPixmap pix = mIconLoader->loadIcon(mIconName, group, iconSize, kstate, mOverlays);
+    const QPixmap pix = mIconLoader.data()->loadIcon(mIconName, group, iconSize, kstate, mOverlays);
     painter->drawPixmap(rect, pix);
 }
 
-QPixmap KIconEngine::pixmap( const QSize & size, QIcon::Mode mode, QIcon::State state )
+QPixmap KIconEngine::pixmap(const QSize & size, QIcon::Mode mode, QIcon::State state)
 {
     Q_UNUSED(state)
 
+    if (!mIconLoader) {
+        QPixmap pm(size);
+        pm.fill(Qt::transparent);
+        return pm;
+    }
+
     const int kstate = qIconModeToKIconState(mode);
     const int iconSize = qMin(size.width(), size.height());
-    QPixmap pix = mIconLoader->loadIcon(mIconName, KIconLoader::Desktop, iconSize, kstate, mOverlays);
+    QPixmap pix = mIconLoader.data()->loadIcon(mIconName, KIconLoader::Desktop, iconSize, kstate, mOverlays);
 
-    if(pix.size() == size)
+    if (pix.size() == size) {
         return pix;
+    }
 
     QPixmap pix2(size);
     pix2.fill(QColor(0,0,0,0));
@@ -111,7 +122,7 @@ QString KIconEngine::key() const
 
 QIconEngineV2 *KIconEngine::clone() const
 {
-    return new KIconEngine(mIconName, mIconLoader, mOverlays);
+    return new KIconEngine(mIconName, mIconLoader.data(), mOverlays);
 }
 
 bool KIconEngine::read(QDataStream &in)
