--- ../kded/kded.h	(revision 918837)
+++ ../kded/kded.h	(revision 918838)
@@ -41,7 +41,7 @@
 {
   Q_OBJECT
 public:
-   Kded(bool checkUpdates);
+   Kded();
    virtual ~Kded();
 
    static Kded *self() { return _self;}
@@ -186,8 +186,6 @@
     */
    KDirWatch* m_pDirWatch;
 
-   bool b_checkUpdates;
-
    /**
     * When a desktop file is updated, a timer is started (5 sec)
     * before rebuilding the binary - so that multiple updates result
