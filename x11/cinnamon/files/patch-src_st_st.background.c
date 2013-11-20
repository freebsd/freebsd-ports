--- src/st/st-background-effect.orig.c	2013-02-24 19:18:24.592514376 +0100
+++ src/st/st-background-effect.c	2013-02-24 19:18:36.891516814 +0100
@@ -225,7 +225,7 @@
        || ( posy != self->posy_old)
        || ( width != self->width_old)
        || ( height != self->height_old)
-       || (time_used > 50.0d))
+       || (time_used > 50.0))
 
   {
     self->posx_old = posx;
