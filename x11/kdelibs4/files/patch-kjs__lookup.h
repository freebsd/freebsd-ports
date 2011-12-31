commit d1fe2074b4fbc8253a4533a7e6be24b4f5b20b8b
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Fri Dec 30 23:25:16 2011 -0200

    Add missing include.
    
    Casting from KJS::JSGlobalObject* to KJS::JSObject* failed with clang
    because it missed the definition of JSGlobalObject.

diff --git a/kjs/lookup.h b/kjs/lookup.h
index 6fabc8f..00622d0 100644
--- ./kjs/lookup.h
+++ ./kjs/lookup.h
@@ -23,6 +23,7 @@
 #ifndef _KJSLOOKUP_H_
 #define _KJSLOOKUP_H_
 
+#include "JSVariableObject.h"
 #include "interpreter.h"
 #include "identifier.h"
 #include "object.h"
