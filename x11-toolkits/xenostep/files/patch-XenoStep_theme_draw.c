
$FreeBSD$

--- XenoStep_theme_draw.c	2002/08/30 16:16:48	1.1
+++ XenoStep_theme_draw.c	2002/08/30 16:17:08
@@ -604,7 +604,7 @@
 				width-=2;	height-=2;
 			}
 		} else if (GTK_IS_BUTTON(widget)) {
-			 if (detail && !strncmp("buttondefault", detail)) {
+			 if (detail && !strcmp("buttondefault", detail)) {
 				newshadow = ((XenoStepThemeData *)style->engine_data)->buttondef_shadow;
 			} else
 			if (!GTK_IS_TOGGLE_BUTTON(widget) && state_type == GTK_STATE_ACTIVE) {
