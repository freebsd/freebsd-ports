--- util/xdg/xdg.cpp.orig	2014-07-28 20:35:44.000000000 +0200
+++ util/xdg/xdg.cpp	2016-01-26 13:01:00.517701000 +0100
@@ -44,13 +44,13 @@ namespace XDG
 
 	QPixmap GetAppPixmap (const QString& name)
 	{
-		const auto prefixes
+		const auto prefixes =
 		{
 			"/usr/share/pixmaps/",
 			"/usr/local/share/pixmaps/"
 		};
 
-		const auto sizes { "192", "128", "96", "72", "64", "48", "36", "32" };
+		const auto sizes = { "192", "128", "96", "72", "64", "48", "36", "32" };
 		const QStringList themes
 		{
 			"/usr/local/share/icons/hicolor/",
