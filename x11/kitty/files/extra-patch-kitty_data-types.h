--- kitty/data-types.h.orig	2022-08-22 11:08:26 UTC
+++ kitty/data-types.h
@@ -159,6 +159,10 @@ typedef union CellAttrs {
 #define NUM_UNDERLINE_STYLES (5u)
 #define SGR_MASK (~(((CellAttrs){.width=WIDTH_MASK, .mark=MARK_MASK}).val))
 
+#ifndef static_assert
+#define static_assert _Static_assert
+#endif
+
 typedef struct {
     color_type fg, bg, decoration_fg;
     sprite_index sprite_x, sprite_y, sprite_z;
