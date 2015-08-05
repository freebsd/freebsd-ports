$OpenBSD: patch-src_core_keybindings-private_h,v 1.1 2015/04/13 08:14:07 jasper Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=747326

--- src/core/keybindings-private.h.orig	Mon Mar 23 18:47:23 2015
+++ src/core/keybindings-private.h	Mon Apr 13 10:06:35 2015
@@ -30,6 +30,7 @@
 #include <gio/gio.h>
 #include <meta/keybindings.h>
 #include <xkbcommon/xkbcommon.h>
+#include "meta-accel-parse.h"
 
 typedef struct _MetaKeyHandler MetaKeyHandler;
 struct _MetaKeyHandler
@@ -53,7 +54,6 @@ typedef struct _MetaResolvedKeyCombo {
  * @keycode: keycode
  * @modifiers: modifiers
  */
-typedef struct _MetaKeyCombo MetaKeyCombo;
 struct _MetaKeyCombo
 {
   unsigned int keysym;
