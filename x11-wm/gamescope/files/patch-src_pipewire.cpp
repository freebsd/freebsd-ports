../src/pipewire.cpp:16:17: error: redefinition of 'log' as different kind of symbol
static LogScope log("pipewire");
                ^
/usr/include/c++/v1/math.h:1007:1: note: previous definition is here
log(_A1 __lcpp_x) _NOEXCEPT {return ::log((double)__lcpp_x);}
^

--- src/pipewire.cpp.orig	2021-09-03 00:18:13 UTC
+++ src/pipewire.cpp
@@ -13,6 +13,9 @@
 #include "pipewire.hpp"
 #include "log.hpp"
 
+#if defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 11000
+#define log gamescope_log
+#endif
 static LogScope log("pipewire");
 
 static struct pipewire_state pipewire_state = { .stream_node_id = SPA_ID_INVALID };
