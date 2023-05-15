--- clients/mwm/WmError.h.orig	2017-08-17 00:38:43 UTC
+++ clients/mwm/WmError.h
@@ -32,7 +32,7 @@ extern int WmXIOErrorHandler (Display *display);
 extern void WmInitErrorHandler (Display *display);
 extern int WmXErrorHandler (Display *display, XErrorEvent *errorEvent);
 extern int WmXIOErrorHandler (Display *display);
-extern void WmXtErrorHandler (char *message);
+extern void WmXtErrorHandler (char *message) _X_NORETURN;
 extern void WmXtWarningHandler (char *message);
 extern void Warning (char *message);
 #ifndef NO_MESSAGE_CATALOG
