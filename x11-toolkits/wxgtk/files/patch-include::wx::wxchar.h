
$FreeBSD$

--- include/wx/wxchar.h.orig	Fri May 25 05:55:35 2001
+++ include/wx/wxchar.h	Mon May 28 22:12:39 2001
@@ -276,12 +276,7 @@
 #    ifdef HAVE_WCSTR_H
 #      include <wcstr.h>
 #    else
-#      ifndef __FreeBSD__
 #        include <wchar.h>
-#      else
-#        include <stdlib.h>
-#        define wxNEED_WCSLEN
-#      endif
 #    endif
 #  endif
 
@@ -511,11 +506,11 @@
 #endif
 
 // checks whether the passed in pointer is NULL and if the string is empty
-inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
+WXDLLEXPORT inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
 
 #ifndef wxNEED_WX_STRING_H
 // safe version of strlen() (returns 0 if passed NULL pointer)
-inline size_t wxStrlen(const wxChar *psz)
+WXDLLEXPORT inline size_t wxStrlen(const wxChar *psz)
    { return psz ? wxStrlen_(psz) : 0; }
 #endif
 
