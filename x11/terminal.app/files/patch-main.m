--- main.m.orig	2009-11-20 21:06:38.000000000 +0100
+++ main.m	2010-05-24 09:20:30.000000000 +0200
@@ -186,8 +186,8 @@
 	[m addItemWithTitle: _(@"Close")
 		action: @selector(performClose:)
 		keyEquivalent: @"w"];
-	[m addItemWithTitle: _(@"Miniaturize all")
-		action: @selector(miniaturizeAll:)
+	[m addItemWithTitle: _(@"Miniaturize Window")
+		action: @selector(miniaturize:)
 		keyEquivalent: @"m"];
 	[menu setSubmenu: m forItem: [menu addItemWithTitle: _(@"Windows")]];
 	[NSApp setWindowsMenu: m];
