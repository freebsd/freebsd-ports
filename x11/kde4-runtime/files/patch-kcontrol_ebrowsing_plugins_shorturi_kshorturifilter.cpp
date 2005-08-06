--- kcontrol/ebrowsing/plugins/shorturi/kshorturifilter.cpp.orig	Sat Aug  6 01:48:21 2005
+++ kcontrol/ebrowsing/plugins/shorturi/kshorturifilter.cpp	Sat Aug  6 01:58:48 2005
@@ -216,6 +216,7 @@
   QString path;
   QString ref;
   QString query;
+  QString nameFilter;
 
   if (KURL::isRelativeURL(cmd) && QDir::isRelativePath(cmd)) {
      path = cmd;
@@ -228,7 +229,8 @@
       // but not for "/tmp/a#b", if "a#b" is an existing file,
       // or for "/tmp/a?b" (#58990)
       if ( ( url.hasRef() || !url.query().isEmpty() ) // avoid the calling exists() when not needed
-           && QFile::exists(url.path()) )
+           && QFile::exists(url.path())
+           && !url.path().endsWith(QFL1("/")) ) // /tmp/?foo is a namefilter, not a query
       {
         path = url.path();
         ref = url.ref();
@@ -338,6 +340,24 @@
   if( isLocalFullPath && !exists )
   {
     exists = ( stat( QFile::encodeName(path).data() , &buff ) == 0 );
+    if ( !exists ) {
+      // Support for name filter (/foo/*.txt), see also KonqMainWindow::detectNameFilter
+      // If the app using this filter doesn't support it, well, it'll simply error out itself
+      int lastSlash = path.findRev( '/' );
+      if ( lastSlash > -1 && path.find( ' ', lastSlash ) == -1 ) // no space after last slash, otherwise it's more likely command-line arguments
+      {
+        QString fileName = path.mid( lastSlash + 1 );
+        QString testPath = path.left( lastSlash + 1 );
+        if ( ( fileName.find( '*' ) != -1 || fileName.find( '[' ) != -1 || fileName.find( '?' ) != -1 )
+           && stat( QFile::encodeName(testPath).data(), &buff ) == 0 )        
+        {
+          nameFilter = fileName;
+	  kdDebug() << "Setting nameFilter to " << nameFilter << endl;
+          path = testPath;
+          exists = true;
+        }
+      }
+    }
   }
 
   //kdDebug() << "path =" << path << " isLocalFullPath=" << isLocalFullPath << " exists=" << exists << endl;
@@ -370,7 +390,9 @@
     // Open "uri" as file:/xxx if it is a non-executable local resource.
     if( isDir || S_ISREG( buff.st_mode ) )
     {
-      //kdDebug() << "Abs path as local file" << endl;
+      //kdDebug() << "Abs path as local file or directory" << endl;
+      if ( !nameFilter.isEmpty() )
+        u.setFileName( nameFilter );
       setFilteredURI( data, u );
       setURIType( data, ( isDir ) ? KURIFilterData::LOCAL_DIR : KURIFilterData::LOCAL_FILE );
       return true;
