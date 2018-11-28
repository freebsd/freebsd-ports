--- Cutter.cpp.orig	2018-11-27 21:55:04 UTC
+++ Cutter.cpp
@@ -111,7 +111,7 @@ QList<QString> CutterCore::sdbListKeys(QString path)
         SdbList *l = sdb_foreach_list(root, false);
         ls_foreach(l, iter, vsi) {
             SdbKv *nsi = (SdbKv *)vsi;
-            list << nsi->key;
+            list << reinterpret_cast<char *>(nsi->base.key);
         }
     }
     return list;
@@ -323,26 +323,6 @@ void CutterCore::openFile(QString path, RVA mapaddr)
     }
 }
 
-void CutterCore::analyze(int level,  QList<QString> advanced)
-{
-    CORE_LOCK();
-    /*
-     * Levels
-     * Level 1: aaa
-     * Level 2: aaaa
-     */
-
-    if (level == 1) {
-        r_core_cmd0(core_, "aaa");
-    } else if (level == 2) {
-        r_core_cmd0(core_, "aaaa");
-    } else if (level == 3) {
-        for (QString option : advanced) {
-            r_core_cmd0(core_, option.toStdString().c_str());
-        }
-    }
-}
-
 void CutterCore::renameFunction(const QString &oldName, const QString &newName)
 {
     cmdRaw("afn " + newName + " " + oldName);
@@ -549,11 +529,6 @@ ut64 CutterCore::math(const QString &expr)
     return r_num_math(this->core_ ? this->core_->num : NULL, expr.toUtf8().constData());
 }
 
-QString CutterCore::itoa(ut64 num, int rdx)
-{
-    return QString::number(num, rdx);
-}
-
 void CutterCore::setConfig(const QString &k, const QString &v)
 {
     CORE_LOCK();
@@ -716,51 +691,6 @@ QString CutterCore::createFunctionAt(RVA addr, QString
     return ret;
 }
 
-void CutterCore::markString(RVA addr)
-{
-    cmd("Cs @" + RAddressString(addr));
-}
-
-int CutterCore::get_size()
-{
-    CORE_LOCK();
-    RBinObject *obj = r_bin_get_object(core_->bin);
-    //return obj->size;
-    return obj != nullptr ? obj->obj_size : 0;
-}
-
-ulong CutterCore::get_baddr()
-{
-    CORE_LOCK();
-    ulong baddr = r_bin_get_baddr(core_->bin);
-    return baddr;
-}
-
-QList<QList<QString>> CutterCore::get_exec_sections()
-{
-    QList<QList<QString>> ret;
-
-    QString text = cmd("S*~^S");
-    for (QString line : text.split("\n")) {
-        QStringList fields = line.split(" ");
-        if (fields.length() == 7) {
-            if (fields[6].contains("x")) {
-                QList<QString> tmp = QList<QString>();
-                tmp << fields[2];
-                tmp << fields[3];
-                tmp << fields[5];
-                ret << tmp;
-            }
-        }
-    }
-    return ret;
-}
-
-QString CutterCore::getOffsetInfo(QString addr)
-{
-    return cmd("ao @ " + addr);
-}
-
 QJsonDocument CutterCore::getRegistersInfo()
 {
     return cmdj("aeafj");
@@ -1219,29 +1149,6 @@ QStringList CutterCore::getStats()
     stats << cmd("f~?").trimmed();
 
     return stats;
-}
-
-QString CutterCore::getSimpleGraph(QString function)
-{
-    // New styles
-    QString graph = "graph [bgcolor=invis, splines=polyline];";
-    QString node =
-        "node [style=\"filled\" fillcolor=\"#4183D7\" shape=box fontname=\"Courier\" fontsize=\"8\" color=\"#4183D7\" fontcolor=\"white\"];";
-    QString arrow = "edge [arrowhead=\"normal\";]";
-
-    // Old styles
-    QString old_graph = "graph [bgcolor=white fontsize=8 fontname=\"Courier\"];";
-    //QString old_node = "node [color=lightgray, style=filled shape=box];";
-    QString old_node = "node [fillcolor=gray style=filled shape=box];";
-    QString old_arrow = "edge [arrowhead=\"vee\"];";
-
-    QString dot = cmd("aga @ " + function).trimmed();
-    dot.replace(old_graph, graph);
-    dot.replace(old_node, node);
-    dot.replace(old_arrow, arrow);
-    dot.replace("fillcolor=blue", "fillcolor=\"#EC644B\", color=\"#EC644B\"");
-
-    return dot;
 }
 
 void CutterCore::setGraphEmpty(bool empty)
