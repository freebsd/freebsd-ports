Index: kdecore/kidna.cpp
===================================================================
RCS file: /home/kde/kdelibs/kdecore/kidna.cpp,v
retrieving revision 1.9.4.1
diff -u -5 -p -d -r1.9.4.1 kidna.cpp
--- kdecore/kidna.cpp	4 Feb 2004 11:43:34 -0000	1.9.4.1
+++ kdecore/kidna.cpp	13 Mar 2004 20:24:13 -0000
@@ -21,16 +21,16 @@
 
 #include "kidna.h"
 
 #include <kdebug.h>
 
-#include "ltdl.h"
+#include <dlfcn.h>
 #include <stdlib.h>
 
 #define IDNA_SUCCESS 0
 
-static lt_dlhandle KIDNA_lib; // = 0
+void *KIDNA_lib; // = 0
 static bool KIDNA_lib_load_failed; // = false
 
 typedef int (*KIDNA_utf8_to_ace_t)(const char *, char **, int);
 typedef int (*KIDNA_utf8ace_to_utf8_t)(const char *, char **, int);
 
@@ -38,27 +38,27 @@ static KIDNA_utf8_to_ace_t KIDNA_utf8_to
 static KIDNA_utf8ace_to_utf8_t KIDNA_utf8ace_to_utf8; // = 0
 
 static void KIDNA_load_lib()
 {
    KIDNA_lib_load_failed = true; // Unless proven otherwise
-   KIDNA_lib = lt_dlopen("/usr/local/lib/libidn.la");
+   KIDNA_lib = dlopen("%%LOCALBASE%%/lib/libidn.so", RTLD_LAZY);
    if (!KIDNA_lib) 
    {
-      KIDNA_lib = lt_dlopen("/usr/lib/libidn.la");
+      KIDNA_lib = dlopen("/usr/lib/libidn.so", RTLD_LAZY);
    }
    
    if (!KIDNA_lib) 
       return; // Error
 
-   KIDNA_utf8_to_ace = (KIDNA_utf8_to_ace_t) lt_dlsym(KIDNA_lib, "idna_to_ascii_8z");
+   KIDNA_utf8_to_ace = (KIDNA_utf8_to_ace_t) dlsym(KIDNA_lib, "idna_to_ascii_8z");
    if (!KIDNA_utf8_to_ace)
    {
       kdWarning() << "Symbol idna_utf8_to_ace not found." << endl;   
       return; // Error
    }
          
-   KIDNA_utf8ace_to_utf8 = (KIDNA_utf8ace_to_utf8_t) lt_dlsym(KIDNA_lib, "idna_to_unicode_8z8z");
+   KIDNA_utf8ace_to_utf8 = (KIDNA_utf8ace_to_utf8_t) dlsym(KIDNA_lib, "idna_to_unicode_8z8z");
    if (!KIDNA_utf8ace_to_utf8)
    {
       kdWarning() << "Symbol idna_utf8ace_to_utf8 not found." << endl;   
       return; // Error
    }
