*** pixmap.c.patched	Sun Jan 24 20:26:03 1999
--- pixmap.c	Sun Jan 24 20:28:39 1999
***************
*** 466,472 ****
   *      Construct bitmap search path as follows:
   *              $OPENWINHOME/etc/workspace/patterns
   *              $OPENWINHOME/include/X11/include/bitmaps
!  *              /usr/X11/include/X11/include/bitmaps
   *
   * REMIND: this should be cleaned up so that it doesn't use a fixed-size
   * array.
--- 466,472 ----
   *      Construct bitmap search path as follows:
   *              $OPENWINHOME/etc/workspace/patterns
   *              $OPENWINHOME/include/X11/include/bitmaps
!  *              /usr/X11R6/include/X11/include/bitmaps
   *
   * REMIND: this should be cleaned up so that it doesn't use a fixed-size
   * array.
***************
*** 489,495 ****
          (void)sprintf(bmPath, "%s/include/X11/bitmaps",owHome);
          bitmapSearchPath[i++] = MemNewString(bmPath);
  
!         bitmapSearchPath[i++] = MemNewString("/usr/X11/include/X11/bitmaps");
  
          bitmapSearchPath[i] = (char *)NULL;
  }
--- 489,495 ----
          (void)sprintf(bmPath, "%s/include/X11/bitmaps",owHome);
          bitmapSearchPath[i++] = MemNewString(bmPath);
  
!         bitmapSearchPath[i++] = MemNewString("/usr/X11R6/include/X11/bitmaps");
  
          bitmapSearchPath[i] = (char *)NULL;
  }
