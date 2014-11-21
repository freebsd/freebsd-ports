commit d68703900edc8416fbcd2550cd336cbbb76decb9
Author: Martin Sandsmark <martin.sandsmark@kde.org>
Date:   Thu Nov 13 13:29:01 2014 +0100

    Sanitize path

--- kioslave/bookmarks/kio_bookmarks.cpp
+++ kioslave/bookmarks/kio_bookmarks.cpp
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 
 #include <qregexp.h>
+#include <qtextdocument.h>
 
 #include <kapplication.h>
 #include <kcmdlineargs.h>
@@ -197,7 +198,7 @@ void BookmarksProtocol::get( const KUrl& url )
     echoImage(regexp.cap(1), regexp.cap(2), url.queryItem("size"));
   } else {
     echoHead();
-    echo("<p class=\"message\">" + i18n("Wrong request: %1",path) + "</p>");
+    echo("<p class=\"message\">" + i18n("Bad request: %1", Qt::escape(Qt::escape(url.prettyUrl()))) + "</p>");
   }
   finished();
 }
