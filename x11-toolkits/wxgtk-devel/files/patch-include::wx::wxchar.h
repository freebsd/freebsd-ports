
$FreeBSD$

--- include/wx/wxchar.h.orig	Sun Sep 15 21:19:48 2002
+++ include/wx/wxchar.h	Sat Oct 26 18:06:12 2002
@@ -554,10 +554,10 @@
 #endif // wxUSE_WCHAR_T
 
 // checks whether the passed in pointer is NULL and if the string is empty
-inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
+WXDLLEXPORT inline bool wxIsEmpty(const wxChar *p) { return !p || !*p; }
 
 // safe version of strlen() (returns 0 if passed NULL pointer)
-inline size_t wxStrlen(const wxChar *psz) { return psz ? wxStrlen_(psz) : 0; }
+WXDLLEXPORT inline size_t wxStrlen(const wxChar *psz) { return psz ? wxStrlen_(psz) : 0; }
 
 WXDLLEXPORT bool wxOKlibc(); // for internal use
 
