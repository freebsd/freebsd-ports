--- kdecore/kapplication.cpp	8 Apr 2004 09:56:28 -0000	1.637.2.8
+++ kdecore/kapplication.cpp	14 May 2004 12:24:53 -0000
@@ -2172,7 +2172,7 @@ void KApplication::invokeMailer(const QS
 
    if (command.isEmpty() || command == QString::fromLatin1("kmail")
        || command.endsWith("/kmail"))
-     command = QString::fromLatin1("kmail --composer -s %s -c %c -b %b --body %B --attach %A %t");
+     command = QString::fromLatin1("kmail --composer -s %s -c %c -b %b --body %B --attach %A -- %t");
 
    // TODO: Take care of the preferred terminal app (instead of hardcoding
    // Konsole), this will probably require a rewrite of the configurable
