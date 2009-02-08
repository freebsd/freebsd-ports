--- ../kio/kio/copyjob.cpp	(revision 917169)
+++ ../kio/kio/copyjob.cpp	(revision 917170)
@@ -153,7 +153,7 @@
     QList<CopyInfo> dirs;
     KUrl::List dirsToRemove;
     KUrl::List m_srcList;
-    KUrl::List m_skippedSourceUrls;
+    KUrl::List m_successSrcList;
     KUrl::List::const_iterator m_currentStatSrc;
     bool m_bCurrentSrcIsDir;
     bool m_bCurrentOperationIsLink;
@@ -770,10 +770,6 @@
 
 void CopyJobPrivate::skip( const KUrl & sourceUrl )
 {
-    // If this is one if toplevel sources,
-    // remove it from d->m_srcList, for a correct FilesRemoved() signal
-    // But don't do it right away, we have iterators into that list (#157601)
-    m_skippedSourceUrls.append( sourceUrl );
     dirsToRemove.removeAll( sourceUrl );
 }
 
@@ -857,6 +853,7 @@
     {
         //this is required for the undo feature
         emit q->copyingDone( q, (*it).uSource, (*it).uDest, (*it).mtime, true, false );
+        m_successSrcList.append((*it).uSource);
         m_directoriesCopied.append( *it );
         dirs.erase( it );
     }
@@ -1118,6 +1115,7 @@
             emit q->copyingDone( q, (*it).uSource, (*it).uDest, (*it).mtime, false, false );
             if (m_mode == CopyJob::Move)
                 org::kde::KDirNotify::emitFileMoved( (*it).uSource.url(), (*it).uDest.url() );
+            m_successSrcList.append((*it).uSource);
         }
         // remove from list, to move on to next file
         files.erase( it );
@@ -1372,7 +1370,7 @@
         KIO::Job * newjob = 0;
         if ( m_mode == CopyJob::Link ) {
             // User requested that a symlink be made
-          JobFlags flags = bOverwrite ? Overwrite : DefaultFlags;
+            const JobFlags flags = bOverwrite ? Overwrite : DefaultFlags;
             newjob = linkNextFile(uSource, uDest, flags);
             if (!newjob)
                 return;
@@ -1384,7 +1382,7 @@
                   (uSource.pass() == uDest.pass()))
             // Copying a symlink - only on the same protocol/host/etc. (#5601, downloading an FTP file through its link),
         {
-            JobFlags flags = bOverwrite ? Overwrite : DefaultFlags;
+            const JobFlags flags = bOverwrite ? Overwrite : DefaultFlags;
             KIO::SimpleJob *newJob = KIO::symlink( (*it).linkDest, uDest, flags | HideProgressInfo /*no GUI*/ );
             Scheduler::scheduleJob(newJob);
             newjob = newJob;
@@ -1509,23 +1507,6 @@
         // but then we need to jump to the else part below. Maybe with a recursive call?
 #endif
     } else {
-        // Finished - tell the world
-        if ( !m_bOnlyRenames )
-        {
-            KUrl url( m_globalDest );
-            if ( m_globalDestinationState != DEST_IS_DIR || m_asMethod )
-                url.setPath( url.directory() );
-            //kDebug(7007) << "KDirNotify'ing FilesAdded " << url;
-            org::kde::KDirNotify::emitFilesAdded( url.url() );
-
-            Q_FOREACH(const KUrl& url, m_skippedSourceUrls)
-                m_srcList.removeAll(url);
-
-            if ( m_mode == CopyJob::Move && !m_srcList.isEmpty() ) {
-                //kDebug(7007) << "KDirNotify'ing FilesRemoved " << m_srcList.toStringList();
-                org::kde::KDirNotify::emitFilesRemoved( m_srcList.toStringList() );
-            }
-        }
         if (m_reportTimer)
             m_reportTimer->stop();
         --m_processedFiles; // undo the "start at 1" hack
@@ -1535,6 +1516,27 @@
     }
 }
 
+void CopyJob::emitResult()
+{
+    Q_D(CopyJob);
+    // Before we go, tell the world about the changes that were made.
+    // Even if some error made us abort midway, we might still have done
+    // part of the job so we better update the views! (#118583)
+    if (!d->m_bOnlyRenames) {
+        KUrl url(d->m_globalDest);
+        if (d->m_globalDestinationState != DEST_IS_DIR || d->m_asMethod)
+            url.setPath(url.directory());
+        //kDebug(7007) << "KDirNotify'ing FilesAdded " << url;
+        org::kde::KDirNotify::emitFilesAdded( url.url() );
+
+        if (d->m_mode == CopyJob::Move && !d->m_successSrcList.isEmpty()) {
+            kDebug(7007) << "KDirNotify'ing FilesRemoved" << d->m_successSrcList.toStringList();
+            org::kde::KDirNotify::emitFilesRemoved(d->m_successSrcList.toStringList());
+        }
+    }
+    Job::emitResult();
+}
+
 void CopyJobPrivate::slotProcessedSize( KJob*, qulonglong data_size )
 {
   Q_Q(CopyJob);
@@ -1801,6 +1803,7 @@
         kDebug(7007) << "Renaming succeeded, move on";
         ++m_processedFiles;
         emit q->copyingDone( q, *m_currentStatSrc, dest, -1 /*mtime unknown, and not needed*/, true, true );
+        m_successSrcList.append(*m_currentStatSrc);
         statNextSrc();
     }
 }
