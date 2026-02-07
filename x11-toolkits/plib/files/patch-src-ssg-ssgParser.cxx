Index: src/ssg/ssgParser.cxx
===================================================================
--- src/ssg/ssgParser.cxx.orig
+++ src/ssg/ssgParser.cxx
@@ -57,18 +57,18 @@ void _ssgParser::error( const char *form
   char msgbuff[ 255 ];
   va_list argp;
 
-  char* msgptr = msgbuff;
-  if (linenum)
-  {
-    msgptr += sprintf ( msgptr,"%s, line %d: ",
-      path, linenum );
-  }
-
   va_start( argp, format );
-  vsprintf( msgptr, format, argp );
+  vsnprintf( msgbuff, sizeof(msgbuff)-1, format, argp );
   va_end( argp );
+  
+  msgbuff[sizeof(msgbuff)-1] = '\0';
 
-  ulSetError ( UL_WARNING, "%s", msgbuff ) ;
+  if (linenum)
+  {
+    ulSetError ( UL_WARNING, "%s, line %d: %s", path, linenum, msgbuff ) ;
+  } else {
+    ulSetError ( UL_WARNING, "%s", msgbuff ) ;
+  }
 }
 
 
@@ -78,18 +78,18 @@ void _ssgParser::message( const char *fo
   char msgbuff[ 255 ];
   va_list argp;
 
-  char* msgptr = msgbuff;
-  if (linenum)
-  {
-    msgptr += sprintf ( msgptr,"%s, line %d: ",
-      path, linenum );
-  }
-
   va_start( argp, format );
-  vsprintf( msgptr, format, argp );
+  vsnprintf( msgbuff, sizeof(msgbuff)-1, format, argp );
   va_end( argp );
+  
+  msgbuff[sizeof(msgbuff)-1] = '\0';
 
-  ulSetError ( UL_DEBUG, "%s", msgbuff ) ;
+  if (linenum)
+  {
+    ulSetError ( UL_DEBUG, "%s, line %d: %s", path, linenum, msgbuff ) ;
+  } else {
+    ulSetError ( UL_DEBUG, "%s", msgbuff ) ;
+  }
 }
 
 // Opens the file and does a few internal calculations based on the spec.
