--- Cutter.h.orig	2018-10-08 07:20:46 UTC
+++ Cutter.h
@@ -17,14 +17,9 @@
 #include <QJsonDocument>
 #include <QErrorMessage>
 
-#define HAVE_LATEST_LIBR2 false
-
 #define CutterRListForeach(list, it, type, x) \
     if (list) for (it = list->head; it && ((x=(type*)it->data)); it = it->n)
 
-#define __alert(x) QMessageBox::question (this, "Alert", QString(x), QMessageBox::Ok)
-#define __question(x) (QMessageBox::Yes==QMessageBox::question (this, "Alert", QString(x), QMessageBox::Yes| QMessageBox::No))
-
 #define APPNAME "Cutter"
 
 #define Core() (CutterCore::getInstance())
@@ -60,8 +55,6 @@ class RCoreLocked (public)
     ~RCoreLocked();
     operator RCore *() const;
     RCore *operator->() const;
-    RVA seek(RVA offset);
-    RVA getSeek();
 };
 
 inline QString RAddressString(RVA addr)
@@ -398,7 +391,6 @@ class CutterCore: public QObject (public)
     QString cmdFunctionAt(QString addr);
     QString cmdFunctionAt(RVA addr);
     QString createFunctionAt(RVA addr, QString name);
-    void markString(RVA addr);
 
     /* Flags */
     void delFlag(RVA addr);
@@ -434,9 +426,6 @@ class CutterCore: public QObject (public)
     void loadScript(const QString &scriptname);
     QJsonArray getOpenedFiles();
 
-    /* Analysis functions */
-    void analyze(int level, QList<QString> advanced);
-
     /* Seek functions */
     void seek(QString thing);
     void seek(ut64 offset);
@@ -464,7 +453,6 @@ class CutterCore: public QObject (public)
 
     /* Math functions */
     ut64 math(const QString &expr);
-    QString itoa(ut64 num, int rdx = 16);
 
     /* Config functions */
     void setConfig(const QString &k, const QString &v);
@@ -491,12 +479,8 @@ class CutterCore: public QObject (public)
     QList<QString> sdbListKeys(QString path);
     QString sdbGet(QString path, QString key);
     bool sdbSet(QString path, QString key, QString val);
-    int get_size();
-    ulong get_baddr();
-    QList<QList<QString>> get_exec_sections();
-    QString getOffsetInfo(QString addr);
 
-    // Debug
+    /* Debug */
     QJsonDocument getRegistersInfo();
     QJsonDocument getRegisterValues();
     QString getRegisterName(QString registerRole);
@@ -531,6 +515,7 @@ class CutterCore: public QObject (public)
     int currentlyAttachedToPID = -1;
     QString currentlyOpenFile;
 
+    /* Pseudocode */
     QString getDecompiledCodePDC(RVA addr);
     bool getR2DecAvailable();
     QString getDecompiledCodeR2Dec(RVA addr);
@@ -540,7 +525,6 @@ class CutterCore: public QObject (public)
     QJsonDocument getSignatureInfo();
     QJsonDocument getFileVersionInfo();
     QStringList getStats();
-    QString getSimpleGraph(QString function);
     void setGraphEmpty(bool empty);
     bool isGraphEmpty();
 
@@ -629,7 +613,6 @@ signals:
     void refreshCodeViews();
     void stackChanged();
 
-    void notesChanged(const QString &notes);
     void projectSaved(const QString &name);
 
     /*!
@@ -654,8 +637,6 @@ signals:
 
     void newMessage(const QString &msg);
     void newDebugMessage(const QString &msg);
-
-public slots:
 
 private:
     MemoryWidgetType memoryWidgetPriority;
