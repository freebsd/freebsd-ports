--- kio/kio/kzip.cpp  #1.56:1.57
@@ -382,4 +382,5 @@ bool KZip::openArchive( int mode )
                 kdWarning(7040) << "KSaveFile creation for " << m_filename << " failed, " << strerror( d->m_saveFile->status() ) << endl;
                 delete d->m_saveFile;
+                d->m_saveFile = 0;
                 return false;
             }
