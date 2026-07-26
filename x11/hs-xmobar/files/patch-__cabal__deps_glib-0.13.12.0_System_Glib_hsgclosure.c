https://github.com/gtk2hs/gtk2hs/pull/349

--- _cabal_deps/glib-0.13.12.0/System/Glib/hsgclosure.c.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/glib-0.13.12.0/System/Glib/hsgclosure.c
@@ -108,7 +108,7 @@ gtk2hs_closure_marshal(GClosure *closure,
     
     /* perform the call */
     #if __GLASGOW_HASKELL__>=704
-    rts_evalIO(&cap, rts_apply(CAP (HaskellObj)runIO_closure, call),&ret);
+    rts_evalIO(&cap, rts_apply(CAP (HaskellObj)ghc_hs_iface->runIO_closure, call),&ret);
     #else
     cap=rts_evalIO(CAP rts_apply(CAP (HaskellObj)runIO_closure, call),&ret);
     #endif
