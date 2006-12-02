--- xpcom_profile.h.orig	Wed Nov 15 17:47:13 2006
+++ xpcom_profile.h	Wed Nov 15 17:41:25 2006
@@ -32,7 +32,7 @@
 #define NDEBUG
 
 #include "nsCOMPtr.h"
-#include "nsProfileDirServiceProvider.h"
+#include "profdirserviceprovider/nsProfileDirServiceProvider.h"
 #include "xpcom_stats.h"
 
 #endif /* INC_xpcom_profile_H */
