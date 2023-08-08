In file included from ../.build/kwin_x11_lib_autogen/mocs_compilation.cpp:10:
In file included from ../.build/kwin_x11_lib_autogen/TRO3DFMZQE/moc_effects.cpp:10:
In file included from render/x11/effects.h:9:
In file included from render/x11/effect/blur_integration.h:8:
In file included from render/x11/effect/blur_update.h:8:
In file included from render/effect/internal_win_update.h:9:
render/effect/internal_win_properties.h:46:62: error: implicit instantiation of undefined template 'std::array<std::variant<KWin::render::internal_effect_property<QRegion>>, 1>'
inline std::array<std::variant<internal_region_property>, 1> get_internal_blur_properties()
                                                             ^
/usr/include/c++/v1/__tuple:219:64: note: template is declared here
template <class _Tp, size_t _Size> struct _LIBCPP_TEMPLATE_VIS array;
                                                               ^

--- render/effect/internal_win_properties.h.orig	2022-06-14 17:35:07 UTC
+++ render/effect/internal_win_properties.h
@@ -7,6 +7,7 @@
 
 #include <KWindowEffects>
 #include <QVariant>
+#include <array>
 #include <string_view>
 #include <variant>
 
