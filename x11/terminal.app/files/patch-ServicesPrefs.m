--- ServicesPrefs.m.orig	2008-05-25 21:48:19.000000000 +0200
+++ ServicesPrefs.m	2010-05-23 09:01:38.000000000 +0200
@@ -7,8 +7,11 @@
 of the License. See COPYING or main.m for more information.
 */
 
+#include <Foundation/NSBundle.h>
+#include <Foundation/NSDictionary.h>
 #include <Foundation/NSString.h>
 #include <Foundation/NSUserDefaults.h>
+#include <Foundation/NSValue.h>
 #include <AppKit/NSButton.h>
 #include <AppKit/NSPopUpButton.h>
 #include <AppKit/NSTextField.h>
