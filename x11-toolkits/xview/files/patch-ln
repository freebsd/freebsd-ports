*** lib/libxview/pw/pw_line.c.orig	Sat Jan 23 19:46:47 1999
--- lib/libxview/pw/pw_line.c	Sat Jan 23 19:49:44 1999
***************
*** 26,32 ****
  {
      XGCValues       gc_val;
      unsigned long   gc_mask = GCLineWidth | GCLineStyle;
!     char           *dash_set;
      int             p_len;
      char           *pw_short_to_char();
      Xv_Drawable_info *info;
--- 26,32 ----
  {
      XGCValues       gc_val;
      unsigned long   gc_mask = GCLineWidth | GCLineStyle;
!     char           *dash_set = NULL;
      int             p_len;
      char           *pw_short_to_char();
      Xv_Drawable_info *info;
*** lib/libxview/pw/xv_rop.c.orig	Sat Jan 23 19:47:07 1999
--- lib/libxview/pw/xv_rop.c	Sat Jan 23 20:10:57 1999
***************
*** 171,190 ****
  	    height = (height > ((Pixrect *) src)->pr_size.y) ?
  		((Pixrect *) src)->pr_size.y : height;
  
! 	    if (xv_depth(dest_info) == xv_depth(src_info)) {
! 		if (xv_depth(dest_info) == 1) {
! 		    changes.stipple = xv_xid(src_info);
! 		    changes.fill_style = FillOpaqueStippled;
! 		    changes_mask |= GCFillStyle | GCStipple;
! 		} else {
! 		    changes.tile = xv_xid(src_info);
! 		    changes.fill_style = FillTiled;
! 		    changes_mask |=  GCTile | GCFillStyle;
! 		}
! 	    } else if (xv_depth(dest_info) > xv_depth(src_info)) {
! 		changes.stipple = xv_xid(src_info);
! 		changes.fill_style = FillOpaqueStippled;
! 		changes_mask |= GCStipple | GCFillStyle;
  	    } else {
  		xv_error(NULL,
  			 ERROR_STRING,
--- 171,185 ----
  	    height = (height > ((Pixrect *) src)->pr_size.y) ?
  		((Pixrect *) src)->pr_size.y : height;
  
! 	    /* stipple only if we have a bitmap src */
! 	    if (xv_depth(src_info) == 1) {
! 	      changes.stipple = xv_xid(src_info);
! 	      changes.fill_style = FillOpaqueStippled;
! 	      changes_mask |=  GCStipple | GCFillStyle;
! 	    } else if(xv_depth(dest_info) == xv_depth(src_info)) {
! 	      changes.tile = xv_xid(src_info);
! 	      changes.fill_style = FillTiled;
! 	      changes_mask |=  GCTile | GCFillStyle;
  	    } else {
  		xv_error(NULL,
  			 ERROR_STRING,
*** lib/libxview/scrollbar/sb.c.orig	Sat Jan 23 20:12:12 1999
--- lib/libxview/scrollbar/sb.c	Sat Jan 23 20:13:26 1999
***************
*** 43,49 ****
  
  Xv_private void	win_set_no_focus();
  Xv_private Graphics_info	*xv_init_olgx();
! Xv_private_data Defaults_pairs xv_kbd_cmds_value_pairs[4];
  
  /******************************************************************/
  
--- 43,49 ----
  
  Xv_private void	win_set_no_focus();
  Xv_private Graphics_info	*xv_init_olgx();
! extern Defaults_pairs xv_kbd_cmds_value_pairs[4];
  
  /******************************************************************/
  
