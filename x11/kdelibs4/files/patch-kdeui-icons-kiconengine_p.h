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

diff --git a/kdeui/icons/kiconengine_p.h b/kdeui/icons/kiconengine_p.h
index 8095d2a..9fba63c 100644
--- kdeui/icons/kiconengine_p.h
+++ kdeui/icons/kiconengine_p.h
@@ -75,7 +75,7 @@ class KIconEngine : public QIconEngineV2
   private:
     QString mIconName;
     QStringList mOverlays;
-    KIconLoader* mIconLoader;
+    QWeakPointer<KIconLoader> mIconLoader;
 };
 
 inline KIconEngine::~KIconEngine()
