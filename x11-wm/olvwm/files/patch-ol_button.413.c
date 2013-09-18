*** ol_button.413.c.orig	Sun Jan 24 20:16:16 1999
--- ol_button.413.c	Sun Jan 24 20:21:00 1999
***************
*** 8,14 ****
   * a version of olgx 3.2 (from the xview 3.2 release) and don't want to
   * use this file, change the define here
   */
! #ifndef SVR4
  
  /*
   * Based on
--- 8,14 ----
   * a version of olgx 3.2 (from the xview 3.2 release) and don't want to
   * use this file, change the define here
   */
! #if !defined(SVR4) && !defined(XVIEW32)
  
  /*
   * Based on
