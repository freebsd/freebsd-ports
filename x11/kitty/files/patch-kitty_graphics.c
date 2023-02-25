--- kitty/graphics.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/graphics.c
@@ -60,7 +60,7 @@ cache_size(const GraphicsManager *self) { return disk_
 
 
 GraphicsManager*
-grman_alloc() {
+grman_alloc(void) {
     GraphicsManager *self = (GraphicsManager *)GraphicsManager_Type.tp_alloc(&GraphicsManager_Type, 0);
     self->images_capacity = self->capacity = 64;
     self->images = calloc(self->images_capacity, sizeof(Image));
