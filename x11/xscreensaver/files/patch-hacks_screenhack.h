--- hacks/screenhack.h.Dist	Fri Jan 19 20:28:31 2001
+++ hacks/screenhack.h	Sat Dec 22 22:41:45 2001
@@ -98,8 +98,11 @@
 extern void screenhack_handle_events (Display*);
 
 /* Be Posixly correct */
+/* This would work better if the sonar code didn't 
+   use bzero.
 #undef  bzero
 #define bzero  __ERROR_use_memset_not_bzero_in_xscreensaver__
+*/
 #undef  bcopy
 #define bcopy  __ERROR_use_memcpy_not_bcopy_in_xscreensaver__
 
