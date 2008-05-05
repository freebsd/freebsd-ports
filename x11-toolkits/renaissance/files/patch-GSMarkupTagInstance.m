--- Source/Markup/GSMarkupTagInstance.m.orig	2003-02-05 03:38:14.000000000 +0100
+++ Source/Markup/GSMarkupTagInstance.m	2008-05-02 18:18:45.000000000 +0200
@@ -30,6 +30,7 @@
 # include <Foundation/Foundation.h>
 # include "GNUstep.h"
 #else
+# include <Foundation/NSString.h>
 # include <Foundation/NSArray.h>
 # include <Foundation/NSDictionary.h>
 #endif
