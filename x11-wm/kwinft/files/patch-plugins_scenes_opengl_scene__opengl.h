https://gitlab.com/kwinft/kwinft/-/issues/210

In file included from plugins/scenes/opengl/scene_opengl.cpp:30:
plugins/scenes/opengl/scene_opengl.h:93:10: error: no template named 'unordered_map' in namespace 'std'
    std::unordered_map<uint32_t, OpenGLWindow*> windows;
    ~~~~~^

--- plugins/scenes/opengl/scene_opengl.h.orig	2021-06-08 12:27:49 UTC
+++ plugins/scenes/opengl/scene_opengl.h
@@ -30,6 +30,8 @@ along with this program.  If not, see <http://www.gnu.
 #include "decorations/decorationrenderer.h"
 #include "platformsupport/scenes/opengl/backend.h"
 
+#include <unordered_map>
+
 namespace KWin
 {
 class LanczosFilter;
