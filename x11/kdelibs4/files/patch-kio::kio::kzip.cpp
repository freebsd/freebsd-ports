--- kio/kio/kzip.cpp.orig	Fri Jan  3 05:58:47 2003
+++ kio/kio/kzip.cpp	Fri Mar 21 11:13:48 2003
@@ -332,27 +332,43 @@
 
             KArchiveEntry* entry;
             if ( isdir )
-                entry = new KArchiveDirectory( this, entryName, access, time, rootDir()->user(), rootDir()->group(), QString::null );
+            {
+                QString path = QDir::cleanDirPath( name.left( pos ) );
+                KArchiveEntry* ent = rootDir()->entry( path );
+                if ( ent && ent->isDirectory() )
+                {
+                    //kdDebug(7040) << "Directory already exists, NOT going to add it again" << endl;
+                    entry = 0L;
+                }
+                else
+                {
+                    entry = new KArchiveDirectory( this, entryName, access, time, rootDir()->user(), rootDir()->group(), QString::null );
+                    //kdDebug(7040) << "KArchiveDirectory created, entryName= " << entryName << ", name=" << name << endl;
+                }
+            }
             else
             {
                 entry = new KZipFileEntry( this, entryName, access, time, rootDir()->user(), rootDir()->group(), QString::null,
-                                          name, dataoffset, ucsize, cmethod, csize );
+                                        name, dataoffset, ucsize, cmethod, csize );
                 static_cast<KZipFileEntry *>(entry)->setHeaderStart( localheaderoffset );
-                //kdDebug(7040) << "KZipFileEntry created" << endl;
+                //kdDebug(7040) << "KZipFileEntry created, entryName= " << entryName << ", name=" << name << endl;
                 d->m_fileList.append( static_cast<KZipFileEntry *>( entry ) );
             }
 
-            if ( pos == -1 )
+            if ( entry )
             {
-                rootDir()->addEntry(entry);
-            }
-            else
-            {
-                // In some tar files we can find dir/./file => call cleanDirPath
-                QString path = QDir::cleanDirPath( name.left( pos ) );
-                // Ensure container directory exists, create otherwise
-                KArchiveDirectory * tdir = findOrCreate( path );
-                tdir->addEntry(entry);
+                if ( pos == -1 )
+                {
+                    rootDir()->addEntry(entry);
+                }
+                else
+                {
+                    // In some tar files we can find dir/./file => call cleanDirPath
+                    QString path = QDir::cleanDirPath( name.left( pos ) );
+                    // Ensure container directory exists, create otherwise
+                    KArchiveDirectory * tdir = findOrCreate( path );
+                    tdir->addEntry(entry);
+                }
             }
 
             //calculate offset to next entry
