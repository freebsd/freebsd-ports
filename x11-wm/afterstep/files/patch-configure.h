*** configure.h.orig	Sun Mar  2 11:50:40 1997
--- configure.h	Thu Mar 20 21:31:42 1997
***************
*** 1,6 ****
! #define AFTERDIR     "/usr/lib/X11/afterstep"
! #define AFTER_ICONDIR   "/usr/include/X11/bitmaps:/usr/include/X11/pixmaps"
! #define STEPRC         "/usr/lib/X11/afterstep/system.steprc"
  
  /* If you would like gradients, uncomment this */
  #define ENABLE_TEXTURE
--- 1,6 ----
! #define AFTERDIR     "%%PREFIX%%/lib/X11/afterstep"
! #define AFTER_ICONDIR   "%%PREFIX%%/include/X11/bitmaps:%%PREFIX%%/include/X11/pixmaps"
! #define STEPRC         "%%PREFIX%%/lib/X11/afterstep/system.steprc"
  
  /* If you would like gradients, uncomment this */
  #define ENABLE_TEXTURE
***************
*** 17,23 ****
   * Imake wants to leave binaries, then choose the second line here.
   * If you want to install it in a different directory, uncomment and
   * edit the first line */
! #define AFTER_BIN_DIR BINDIR=/usr/bin/X11
  
  /* Compiler over-ride for Imakefiles */
  /* Leave it as shown to get your default compiler */
--- 17,23 ----
   * Imake wants to leave binaries, then choose the second line here.
   * If you want to install it in a different directory, uncomment and
   * edit the first line */
! #define AFTER_BIN_DIR BINDIR=%%PREFIX%%/bin
  
  /* Compiler over-ride for Imakefiles */
  /* Leave it as shown to get your default compiler */
***************
*** 59,65 ****
   ***************************************************************************/
  #define XPM                      
  /*  linker flags needed to locate and link in the Xpm library, if you use it */
! #define XPMLIBRARY -L/usr/lib/X11 -lXpm
  
  /***************************************************************************
   *#define M4
--- 59,65 ----
   ***************************************************************************/
  #define XPM                      
  /*  linker flags needed to locate and link in the Xpm library, if you use it */
! #define XPMLIBRARY -L%%PREFIX%%/lib -lXpm
  
  /***************************************************************************
   *#define M4
