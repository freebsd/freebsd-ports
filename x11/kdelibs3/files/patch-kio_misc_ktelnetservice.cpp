--- kio/misc/ktelnetservice.cpp	18 Feb 2004 11:42:12 -0000	1.7.2.1
+++ kio/misc/ktelnetservice.cpp	13 May 2004 15:12:14 -0000
@@ -77,10 +77,19 @@ int main(int argc, char **argv)
 		cmd << url.user();
 	}
 
+        QString host;
         if (!url.host().isEmpty())
-           cmd << url.host(); // telnet://host
+           host = url.host(); // telnet://host
         else if (!url.path().isEmpty())
-           cmd << url.path(); // telnet:host
+           host = url.path(); // telnet:host
+
+        if (host.isEmpty() || host.startsWith("-"))
+        {
+            kdError() << "Invalid hostname " << host << endl;
+            return 2;
+        }
+
+        cmd << host;
         
 	if (url.port()){
             if ( url.protocol() == "ssh" )
