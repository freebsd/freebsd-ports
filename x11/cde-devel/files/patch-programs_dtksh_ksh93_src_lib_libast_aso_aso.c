--- programs/dtksh/ksh93/src/lib/libast/aso/aso.c.orig	2023-02-15 05:12:10.716298000 -0800
+++ programs/dtksh/ksh93/src/lib/libast/aso/aso.c	2023-02-15 06:25:53.658714000 -0800
@@ -835,7 +835,7 @@
 
 #if defined(_aso_casptr)
 	if (!state.lockf)
-		return _aso_casptr((void**)p, o, n);
+		return _aso_cas64((void**)p, o, n);
 #endif
 	k = lock(state.data, 0, p);
 	if (*(void* volatile*)p == o)
