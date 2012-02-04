commit 4c72106b5db6771e6a6b45580808a4c015682096
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun Jan 1 23:08:15 2012 -0200

    Do not shadow the counter variable in queryForAndUpdateAllXWindows.
    
    `i' was being used as both the uint counter variable and as a QMap
    iterator, which caused a warning with gcc and -Wshadow and made the
    build fail with clang.
    
    CCMAIL: johnflux@gmail.com

diff --git a/libs/ksysguard/processui/ProcessModel.cpp b/libs/ksysguard/processui/ProcessModel.cpp
index 83bfb4b..a9d2d28 100644
--- ./libs/ksysguard/processui/ProcessModel.cpp
+++ ./libs/ksysguard/processui/ProcessModel.cpp
@@ -421,11 +421,11 @@ void ProcessModelPrivate::queryForAndUpdateAllXWindows() {
         return;
     for (uint i=0; i < count; ++i) {
         WId wid = children[i];
-        QMap<qlonglong, XID>::iterator i = mXResClientResources.lowerBound(-(qlonglong)(wid));
-        if(i == mXResClientResources.end())
+        QMap<qlonglong, XID>::iterator iter = mXResClientResources.lowerBound(-(qlonglong)(wid));
+        if(iter == mXResClientResources.end())
             continue; //We couldn't find it this time :-/
 
-        if(-i.key() != (qlonglong)(wid & ~i.value()))
+        if(-iter.key() != (qlonglong)(wid & ~iter.value()))
             continue; //Already added this window
 
         //Get the PID for this window if we do not know it
@@ -438,7 +438,7 @@ void ProcessModelPrivate::queryForAndUpdateAllXWindows() {
         if(!pid)
             continue;
         //We found a window with this client
-        mXResClientResources.erase(i);
+        mXResClientResources.erase(iter);
         KSysGuard::Process *process = mProcesses->getProcess(pid);
         if(!process) return; //shouldn't really happen.. maybe race condition etc
         unsigned long previousPixmapBytes = process->pixmapBytes;
