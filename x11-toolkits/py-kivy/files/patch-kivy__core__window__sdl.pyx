--- kivy/core/window/sdl.pyx
+++ kivy/core/window/sdl.pyx
@@ -35,7 +35,7 @@ cdef extern from "SDL.h":
         unsigned int scancode
         unsigned int sym
         unsigned short mod
-        unsigned int unicode
+        unsigned int unused
 
     ctypedef struct SDL_KeyboardEvent:
         unsigned char state
@@ -282,7 +282,7 @@ def poll():
         action = 'keydown' if event.type == SDL_KEYDOWN else 'keyup'
         mod = event.key.keysym.mod
         scancode = event.key.keysym.scancode
-        unicode = event.key.keysym.unicode
+        unicode = event.key.keysym.unused
         key = event.key.keysym.sym
         return (action, mod, key, scancode, unicode)
     elif event.type == SDL_TEXTINPUT:
