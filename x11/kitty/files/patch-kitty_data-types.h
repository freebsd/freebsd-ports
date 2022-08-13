--- kitty/data-types.h.orig	2022-08-13 20:17:56 UTC
+++ kitty/data-types.h
@@ -164,14 +164,14 @@ typedef struct {
     sprite_index sprite_x, sprite_y, sprite_z;
     CellAttrs attrs;
 } GPUCell;
-static_assert(sizeof(GPUCell) == 20, "Fix the ordering of GPUCell");
+_Static_assert(sizeof(GPUCell) == 20, "Fix the ordering of GPUCell");
 
 typedef struct {
     char_type ch;
     hyperlink_id_type hyperlink_id;
     combining_type cc_idx[3];
 } CPUCell;
-static_assert(sizeof(CPUCell) == 12, "Fix the ordering of CPUCell");
+_Static_assert(sizeof(CPUCell) == 12, "Fix the ordering of CPUCell");
 
 typedef enum { UNKNOWN_PROMPT_KIND = 0, PROMPT_START = 1, SECONDARY_PROMPT = 2, OUTPUT_START = 3 } PromptKind;
 typedef union LineAttrs {
