--- kxkb/rules.cpp	2004/06/28 14:19:03	1.38
+++ kxkb/rules.cpp	2004/08/29 19:05:04	1.39
@@ -17,7 +17,7 @@
 #include "rules.h"
 
 const char* X11DirList[2] = {"/usr/X11R6/lib/X11/", "/usr/local/X11R6/lib/X11/"};
-const char* rulesFileList[2] = {"xkb/rules/xfree86", "xkb/rules/xorg"};
+const char* rulesFileList[2] = {"xkb/rules/xorg", "xkb/rules/xfree86"};
 
 KeyRules::KeyRules():
     m_layouts(90)
