*** fontset.c.orig	Sun Jan 24 20:51:59 1999
--- fontset.c	Sun Jan 24 20:54:54 1999
***************
*** 210,216 ****
  
  	if (notFound)
  	{
!         	(void) sprintf(filename, "/usr/lib/X11/app-defaults/%s/%s",
  			locale, FONT_SETS);
  	}
  
--- 210,216 ----
  
  	if (notFound)
  	{
!         	(void) sprintf(filename, "/usr/X11R6/lib/X11/app-defaults/%s/%s",
  			locale, FONT_SETS);
  	}
  
