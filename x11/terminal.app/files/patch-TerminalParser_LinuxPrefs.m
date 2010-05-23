--- TerminalParser_LinuxPrefs.m.orig	2008-05-25 21:48:19.000000000 +0200
+++ TerminalParser_LinuxPrefs.m	2010-05-23 09:08:25.000000000 +0200
@@ -7,6 +7,8 @@
 of the License. See COPYING or main.m for more information.
 */
 
+#include <Foundation/NSBundle.h>
+#include <Foundation/NSNotification.h>
 #include <Foundation/NSString.h>
 #include <Foundation/NSUserDefaults.h>
 #include <AppKit/NSPopUpButton.h>
