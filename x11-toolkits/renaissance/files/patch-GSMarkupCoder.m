--- Source/Markup/GSMarkupCoder.m.orig	2003-07-15 11:40:54.000000000 +0200
+++ Source/Markup/GSMarkupCoder.m	2008-05-02 18:18:37.000000000 +0200
@@ -31,6 +31,7 @@
 # include <Foundation/Foundation.h>
 # include "GNUstep.h"
 #else
+# include <Foundation/NSString.h>
 # include <Foundation/NSArray.h>
 # include <Foundation/NSData.h>
 #endif
