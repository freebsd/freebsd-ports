--- kdecore/kcharsets.cpp	2003/09/06 19:06:29	1.144
+++ kdecore/kcharsets.cpp	2004/03/12 09:18:03	1.144.2.1
@@ -1,6 +1,6 @@
 /* This file is part of the KDE libraries
     Copyright (C) 1999 Lars Knoll (knoll@kde.org)
-    $Id: kcharsets.cpp,v 1.144 2003/09/06 19:06:29 binner Exp $
+    $Id: kcharsets.cpp,v 1.144.2.1 2004/03/12 09:18:03 kalass Exp $
 
     This library is free software; you can redistribute it and/or
     modify it under the terms of the GNU Library General Public
@@ -497,19 +497,19 @@ QString KCharsets::languageForEncoding( 
 
 QString KCharsets::encodingForName( const QString &descriptiveName )
 {
-    const int left = descriptiveName.find( '(' );
+    const int left = descriptiveName.findRev( '(' );
     
     if (left<0) // No parenthesis, so assume it is a normal encoding name
-	return descriptiveName;
+	return descriptiveName.stripWhiteSpace();
     
-    QString name(descriptiveName.mid(left+2));
+    QString name(descriptiveName.mid(left+1));
     
-    const int right = name.find( ')' );
+    const int right = name.findRev( ')' );
     
     if (right<0) 
         return name;
-	
-    return name.left(right-1);
+
+    return name.left(right).stripWhiteSpace();
 }
 
 QStringList KCharsets::descriptiveEncodingNames()