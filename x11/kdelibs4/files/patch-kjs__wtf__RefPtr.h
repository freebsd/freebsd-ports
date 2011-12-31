commit 01b0c1a8051f372e400d213ac125311c398e4b17
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Fri Dec 30 23:27:31 2011 -0200

    Add missing include.
    
    RefPtr::release() needs PassRefPtr.h for adoptRef(). The include is also
    present in WebKit's wtf.
    
    This should fix another build failure with clang.

diff --git a/kjs/wtf/RefPtr.h b/kjs/wtf/RefPtr.h
index c16397e..493ab05 100644
--- ./kjs/wtf/RefPtr.h
+++ ./kjs/wtf/RefPtr.h
@@ -24,6 +24,7 @@
 
 #include <algorithm>
 #include "AlwaysInline.h"
+#include "PassRefPtr.h"
 
 namespace WTF {
 
