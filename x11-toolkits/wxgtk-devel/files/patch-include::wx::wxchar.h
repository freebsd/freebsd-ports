
$FreeBSD$

--- include/wx/wxchar.h.orig	Mon Dec 10 20:07:02 2001
+++ include/wx/wxchar.h	Sat Jan 19 12:14:57 2002
@@ -532,11 +532,11 @@
 #endif //!Unicode
 
 // checks whether the passed in pointer is NULL and if the string is empty
-inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
+WXDLLEXPORT inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
 
 #ifndef wxNEED_WX_STRING_H
 // safe version of strlen() (returns 0 if passed NULL pointer)
-inline size_t wxStrlen(const wxChar *psz)
+WXDLLEXPORT inline size_t wxStrlen(const wxChar *psz)
    { return psz ? wxStrlen_(psz) : 0; }
 #endif
 
