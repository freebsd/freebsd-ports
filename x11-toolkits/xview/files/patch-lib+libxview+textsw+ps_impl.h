--- lib/libxview/textsw/ps_impl.h.orig	Thu Oct  5 19:26:54 2006
+++ lib/libxview/textsw/ps_impl.h	Thu Oct  5 19:27:04 2006
@@ -134,7 +134,7 @@
 #define	SCRATCH_HAS_WRAPPED(_private)					\
 	((_private)->scratch_length > (_private)->scratch_max_len)
 
-EXTERN_FUNCTION( caddr_t ps_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
+EXTERN_FUNCTION( static caddr_t ps_get, (Es_handle esh, Es_attribute attribute, DOTDOTDOT ));
 
 #endif
 
