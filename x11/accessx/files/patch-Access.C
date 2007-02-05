--- Access.C.orig	Tue Mar 13 23:39:55 2001
+++ Access.C	Tue Jan 30 22:18:00 2007
@@ -21,6 +21,8 @@
 #include <X11/XKBlib.h>
 #include "Access.h"
 
+using namespace std;
+
 //
 // Access()
 //
@@ -152,7 +154,7 @@
     //Get the state of the keyboard.
 
     XkbDescPtr xkb = XkbGetMap(display, 0, XkbUseCoreKbd);
-    if ((int)xkb == BadAlloc || xkb == NULL)
+    if (xkb == NULL)
       {
 	return 5; /*AccessKeyboardQueryFailure;*/
       }
@@ -261,7 +263,7 @@
     //Get the state of the keyboard.
 
     XkbDescPtr xkb = XkbGetMap(display, 0, XkbUseCoreKbd);
-    if ((int)xkb == BadAlloc || xkb == NULL)
+    if (xkb == NULL)
       {
 	return 5; /*AccessKeyboardQueryFailure;*/
       }
