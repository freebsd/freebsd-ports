--- plugins/files/src/plugin.cpp.orig	2023-01-31 09:29:00 UTC
+++ plugins/files/src/plugin.cpp
@@ -116,7 +116,7 @@ void Plugin::updateIndexItems()
     ii.emplace_back(update_item, update_item->text());
 
     // Add trash item
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     auto trash_path = "trash:///";
 #elif defined(Q_OS_MAC)
     auto trash_path = QString("file://%1/.Trash").arg(QDir::homePath());
