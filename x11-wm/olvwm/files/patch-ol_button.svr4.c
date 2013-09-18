*** ol_button.svr4.c.orig	Sun Jan 24 20:21:22 1999
--- ol_button.svr4.c	Sun Jan 24 20:23:34 1999
***************
*** 12,18 ****
   *
   */
  
! #ifdef SVR4
  
  /*
   * Copyright 1989-1990 Sun Microsystems  See LEGAL_NOTICE for terms of
--- 12,18 ----
   *
   */
  
! #if defined(SVR4) || defined(XVIEW32)
  
  /*
   * Copyright 1989-1990 Sun Microsystems  See LEGAL_NOTICE for terms of
