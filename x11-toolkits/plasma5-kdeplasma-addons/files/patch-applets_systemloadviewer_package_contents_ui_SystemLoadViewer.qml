--- applets/systemloadviewer/package/contents/ui/SystemLoadViewer.qml.orig	2020-03-31 14:08:40 UTC
+++ applets/systemloadviewer/package/contents/ui/SystemLoadViewer.qml
@@ -179,12 +179,15 @@ Item {
         onNewData: {
             if (sourceName == sysLoad) {
                 totalCpuLoadProportions[0] = fitCpuLoad(data.value)
+                totalCpuLoadProportionsChanged()
             }
             else if (sourceName == userLoad) {
                 totalCpuLoadProportions[1] = fitCpuLoad(data.value)
+                totalCpuLoadProportionsChanged()
             }
             else if (sourceName == niceLoad) {
                 totalCpuLoadProportions[2] = fitCpuLoad(data.value)
+                totalCpuLoadProportionsChanged()
             }
             else if (sourceName == ioWait) {
                 totalCpuLoadProportions[3] = fitCpuLoad(data.value)
@@ -192,6 +195,7 @@ Item {
             }
             else if (sourceName == memApplication) {
                 memoryUsageProportions[0] = fitMemoryUsage(data.value)
+                memoryUsageProportionsChanged()
             }
             else if (sourceName == memBuffers) {
                 memoryUsageProportions[1] = fitMemoryUsage(data.value)
@@ -250,8 +254,8 @@ Item {
         var swapTotal = swapFree + swapUsed
         var swapPart = i18n("Swap: %1/%2 MiB", Math.round(swapUsed), Math.round(swapTotal))
 
-        var cacheDirty = parseFloat(dataSource.data[dataSource.cacheDirty].value) / 1024
-        var cacheWriteback = parseFloat(dataSource.data[dataSource.cacheWriteback].value) / 1024
+        var cacheDirty = parseFloat(dataSource.data[dataSource.cacheDirty] ? dataSource.data[dataSource.cacheDirty].value : 0) / 1024
+        var cacheWriteback = parseFloat(dataSource.data[dataSource.cacheWriteback] ? dataSource.data[dataSource.cacheWriteback].value : 0) / 1024
         var cachePart = i18n("Cache Dirty, Writeback: %1 MiB, %2 MiB", Math.round(cacheDirty), Math.round(cacheWriteback))
 
         if (cpuClockPart === "") {
