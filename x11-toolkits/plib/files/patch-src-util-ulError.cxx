Index: src/util/ulError.cxx
===================================================================
--- src/util/ulError.cxx.orig
+++ src/util/ulError.cxx
@@ -39,9 +39,11 @@ void ulSetError ( enum ulSeverity severi
 {
   va_list argp;
   va_start ( argp, fmt ) ;
-  vsprintf ( _ulErrorBuffer, fmt, argp ) ;
+  vsnprintf ( _ulErrorBuffer, sizeof(_ulErrorBuffer)-1, fmt, argp ) ;
   va_end ( argp ) ;
- 
+  
+  _ulErrorBuffer[sizeof(_ulErrorBuffer)-1] = '\0';
+
   if ( _ulErrorCB )
   {
     (*_ulErrorCB)( severity, _ulErrorBuffer ) ;
