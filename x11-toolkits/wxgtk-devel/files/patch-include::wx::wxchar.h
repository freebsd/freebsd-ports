
$FreeBSD$

--- include/wx/wxchar.h.orig	Thu Jul  5 06:24:14 2001
+++ include/wx/wxchar.h	Tue Nov 27 13:13:28 2001
@@ -288,12 +288,7 @@
 #    ifdef HAVE_WCSTR_H
 #      include <wcstr.h>
 #    else
-#      if defined(__FreeBSD__) || (defined(__APPLE__) && defined(__UNIX__))
-#        include <stdlib.h>
-#        define wxNEED_WCSLEN
-#      else
 #        include <wchar.h>
-#      endif
 #    endif
 #  endif
 
@@ -523,11 +518,11 @@
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
 
