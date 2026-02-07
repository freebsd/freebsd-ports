--- greeter/keyboard/XcbKeyboardBackend.h.orig	2025-05-14 15:33:28 UTC
+++ greeter/keyboard/XcbKeyboardBackend.h
@@ -4,6 +4,8 @@
 * SPDX-License-Identifier: GPL-2.0-or-later
 ***************************************************************************/
 
+#pragma clang diagnostic ignored "-Wkeyword-macro"
+
 #ifndef XCBKEYBOARDBACKEND_H
 #define XCBKEYBOARDBACKEND_H
 
