--- kdesktop/init.cc.orig	Fri Oct 12 15:11:13 2001
+++ kdesktop/init.cc	Thu Jul 18 06:48:59 2002
@@ -80,6 +80,9 @@
      QFile::encodeName(locate("data", QString("kdesktop/") + fileName)).data(),
      QFile::encodeName(dir).data() );
     system( cmd );
+    cmd.sprintf( "chmod 644 %s/.directory", 
+		 QFile::encodeName(dir).data() );
+    system( cmd );
   }
 }
 
@@ -106,6 +109,9 @@
 	cmd += "' '";
 	cmd += QFile::encodeName(desktopPath + desk.readName());
 	cmd += "'";
+	system( cmd );
+	cmd.sprintf("chmod 644 '%s'",
+		    QFile::encodeName(desktopPath + desk.readName()).data());
 	system( cmd );
     }
 }
