--- kitty/shaders.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/shaders.c
@@ -223,7 +223,7 @@ init_cell_program(void) {
 #define CELL_BUFFERS enum { cell_data_buffer, selection_buffer, uniform_buffer };
 
 ssize_t
-create_cell_vao() {
+create_cell_vao(void) {
     ssize_t vao_idx = create_vao();
 #define A(name, size, dtype, offset, stride) \
     add_attribute_to_vao(CELL_PROGRAM, vao_idx, #name, \
@@ -246,7 +246,7 @@ create_cell_vao() {
 }
 
 ssize_t
-create_graphics_vao() {
+create_graphics_vao(void) {
     ssize_t vao_idx = create_vao();
     add_buffer_to_vao(vao_idx, GL_ARRAY_BUFFER);
     add_attribute_to_vao(GRAPHICS_PROGRAM, vao_idx, "src", 4, GL_FLOAT, 0, NULL, 0);
