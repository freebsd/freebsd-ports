$FreeBSD$

--- arts/kde/kplayobjectfactory.cc.orig	Sat May 19 13:07:41 2001
+++ arts/kde/kplayobjectfactory.cc	Fri Dec  7 10:54:40 2001
@@ -20,6 +20,7 @@
 	*/
 
 #include <kio/kmimetype.h>
+#include <qfile.h>
 #include "kplayobject.h"
 #include "artskde.h"
 #include "kplayobjectfactory.h"
@@ -49,13 +50,13 @@
 		if(mimetype == "application/octet-stream" && m_allowStreaming)
 		{
 			Arts::KIOInputStream instream;
-			instream.openURL(url.prettyURL().latin1());
+			instream.openURL(url.url().latin1());
 	    
 			// TODO: what else than hardcoding audio/x-mp3 ?
 			return new KPlayObject(m_server.createPlayObjectForStream(instream, string("audio/x-mp3"), createBUS), true);
 		}
 		else
-			return new KPlayObject(m_server.createPlayObjectForURL(string(url.path().latin1()), string(mimetype.latin1()), createBUS), false);
+			return new KPlayObject(m_server.createPlayObjectForURL(string(QFile::encodeName(url.path())), string(mimetype.latin1()), createBUS), false);
 	}
 	else
 		return new KPlayObject();

