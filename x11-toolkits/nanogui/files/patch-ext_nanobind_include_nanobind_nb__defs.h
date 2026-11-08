--- ext/nanobind/include/nanobind/nb_defs.h.orig	2026-09-27 03:09:51 UTC
+++ ext/nanobind/include/nanobind/nb_defs.h
@@ -138,7 +138,7 @@
 /* python_error is unusable with libc++ on ELF platforms, where typeinfo is
    compared by pointer. Python imports extensions with RTLD_LOCAL, so the
    weak symbols of the extensions are not correctly merged. */
-#if defined(NB_BACKEND_MODULE) && defined(_LIBCPP_VERSION) && !defined(__APPLE__)
+#if defined(NB_BACKEND_MODULE) && defined(_LIBCPP_VERSION) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #    error "nanobind's split mode requires libstdc++ on ELF platforms"
 #endif
 
