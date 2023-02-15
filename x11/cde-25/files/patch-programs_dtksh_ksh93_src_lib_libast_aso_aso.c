--- programs/dtksh/ksh93/src/lib/libast/aso/aso.c.orig	2023-02-15 05:12:56.531750000 -0800
+++ programs/dtksh/ksh93/src/lib/libast/aso/aso.c	2023-02-15 06:24:18.124862000 -0800
@@ -835,7 +835,7 @@
 
 #if defined(_aso_casptr)
 	if (!state.lockf)
-		return _aso_casptr((void**)p, o, n);
+		return _aso_cas64((void**)p, o, n);
 #endif
 	k = lock(state.data, 0, p);
 	if (*(void* volatile*)p == o)
