--- lib/libxview/icon/icon.c.orig	Mon Sep 29 00:02:30 2003
+++ lib/libxview/icon/icon.c	Mon Sep 29 00:02:30 2003
@@ -343,15 +343,32 @@
     val.ts_x_origin = 0;
     val.ts_y_origin = 0;	
     val_mask = GCForeground | GCBackground | GCFunction | 
-               GCPlaneMask | GCFillStyle | GCTileStipXOrigin | 
+               GCPlaneMask | GCTileStipXOrigin | 
                GCTileStipYOrigin;
     XChangeGC(display, gc, val_mask, &val );
 
     if (PR_NOT_MPR(((Pixrect *) icon->ic_mpr)))  {
 	DRAWABLE_INFO_MACRO( (Xv_opaque) icon->ic_mpr, src_info );
+
+	/* stipple only if we have a bitmap icon */
+	if (xv_depth(src_info) == 1) {
+		val.stipple = xv_xid(src_info);
+		val.fill_style = FillOpaqueStippled;
+		val_mask = GCFillStyle | GCStipple;
+	} else if (xv_depth(info) == xv_depth(src_info)) {
+		val.tile = xv_xid(src_info);
+		val.fill_style = FillTiled;
+		val_mask = GCFillStyle | GCTile;
+	} else {
+		xv_error(NULL,
+			ERROR_STRING,
+		 	XV_MSG("icon: can't handle drawables of different depth"),
+		 	0);
+		return (XV_ERROR);
+	}	
+
 	val.clip_mask = xv_xid(mask_info);
-	val.stipple = xv_xid(src_info);
-	val_mask = GCStipple | GCClipMask;
+	val_mask |= GCClipMask;
 	XChangeGC(display, gc, val_mask, &val );
 
 	if ( xv_rop_internal( display, xid, gc, icon->ic_gfxrect.r_left + x,
