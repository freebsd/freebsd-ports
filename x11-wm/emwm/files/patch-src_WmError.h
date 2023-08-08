--- src/WmError.h.orig	2023-07-10 10:58:21 UTC
+++ src/WmError.h
@@ -29,7 +29,7 @@ extern void PrintFormatted(char *f, char *s0, char *s1
 extern void WmInitErrorHandler (Display *display);
 extern int WmXErrorHandler (Display *display, XErrorEvent *errorEvent);
 extern int WmXIOErrorHandler (Display *display);
-extern void WmXtErrorHandler (char *message);
+extern void WmXtErrorHandler (char *message) __attribute__((noreturn));
 extern void WmXtWarningHandler (char *message);
 extern void Warning (char *message);
 #ifndef NO_MESSAGE_CATALOG
