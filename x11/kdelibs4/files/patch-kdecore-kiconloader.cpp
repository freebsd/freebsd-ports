--- kdecore/kiconloader.cpp	Wed May  8 14:27:24 2002
+++ /home/alane/kiconloader-3.0.cpp	Sat Jun  8 12:05:25 2002
@@ -1,6 +1,6 @@
 /* vi: ts=8 sts=4 sw=4
  *
- * $Id: kiconloader.cpp,v 1.186 2002/03/18 00:27:25 carewolf Exp $
+ * $Id: kiconloader.cpp,v 1.186.2.2 2002/06/03 11:14:08 faure Exp $
  *
  * This file is part of the KDE project, module kdecore.
  * Copyright (C) 2000 Geert Jansen <jansen@kde.org>
@@ -220,7 +220,7 @@
 	d->mpGroups[i].size = config->readNumEntry("Size", 0);
 	d->mpGroups[i].dblPixels = config->readBoolEntry("DoublePixels", false);
 	if (QPixmap::defaultDepth()>8)
-	    d->mpGroups[i].alphaBlending = config->readBoolEntry("AlphaBlending", false);
+	    d->mpGroups[i].alphaBlending = config->readBoolEntry("AlphaBlending", true);
 	else
 	    d->mpGroups[i].alphaBlending = false;
 
@@ -266,21 +266,23 @@
 
 void KIconLoader::addAppThemes(const QString& appname)
 {
-    KIconThemeNode *node = 0L;
-    KIconTheme *theme = 0L;
-
-    theme = new KIconTheme("hicolor", appname);
-    if (theme->isValid())
-	node = new KIconThemeNode(theme);
-    else
-	delete theme;
-
-    if (node)
+    if ( KIconTheme::current() != "hicolor" )
     {
-	node->links.append(d->mpThemeRoot);
-	d->mpThemeRoot = node;
+        KIconTheme *def = new KIconTheme(KIconTheme::current(), appname);
+        if (def->isValid())
+        {
+            KIconThemeNode* node = new KIconThemeNode(def);
+            d->mpThemeRoot->links.append(node);
+            addBaseThemes(node, appname);
+        }
+        else
+            delete def;
     }
 
+    KIconTheme *def = new KIconTheme(QString::fromLatin1("hicolor"), appname);
+    KIconThemeNode* node = new KIconThemeNode(def);
+    d->mpThemeRoot->links.append(node);
+    addBaseThemes(node, appname);
 }
 
 void KIconLoader::addBaseThemes(KIconThemeNode *node, const QString &appname)
