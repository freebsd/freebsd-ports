In file included from ../src/CompositorFont.cpp:5:
../src/compositor.h:75:14: error: implicit instantiation of undefined template 'std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >'
        std::string title;
                    ^
/usr/include/c++/v1/iosfwd:210:32: note: template is declared here
    class _LIBCPP_TEMPLATE_VIS basic_string;
                               ^

--- src/compositor.h.orig	2020-01-11 22:22:06 UTC
+++ src/compositor.h
@@ -9,6 +9,8 @@
 #include <xcb/shm.h>
 #include <xcb/dri3.h>
 
+#include <string>
+
 //struct gbm_device;
 
 namespace Backend{
