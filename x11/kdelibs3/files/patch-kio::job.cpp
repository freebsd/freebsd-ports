--- kio/job.cpp.20011019	Fri Oct 19 16:09:57 2001
+++ kio/job.cpp	Tue Oct 30 21:49:15 2001
@@ -2472,7 +2472,7 @@
             // But for files coming from TAR, we want to preserve permissions -> we use default perms only if from remote
             // The real fix would be KProtocolInfo::inputType(protocol) == T_FILESYSTEM, but we can't access ksycoca from here !
             bool remoteSource = !(*it).uSource.isLocalFile() && ((*it).uSource.protocol() != "tar"); // HACK
-            mode_t permissions = ( remoteSource && (*it).uDest.isLocalFile() ) ? (mode_t)-1 : (*it).permissions;
+            int permissions = ( remoteSource && (*it).uDest.isLocalFile() ) ? -1 : (*it).permissions;
             KIO::FileCopyJob * copyJob = KIO::file_copy( (*it).uSource, (*it).uDest, permissions, bOverwrite, false, false/*no GUI*/ );
             copyJob->setSourceSize( (*it).size );
             newjob = copyJob;
