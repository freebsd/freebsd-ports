*** lib/libxview/textsw/txt_e_menu.c.org	Sun Jan 21 16:01:52 2001
--- lib/libxview/textsw/txt_e_menu.c	Sun Jan 21 16:03:27 2001
***************
*** 144,153 ****
--- 144,160 ----
  
  #ifdef __FreeBSD__
  	/* Gee, still?... We will try the old fashioned way */
+ 	/* If it is never defined, EXTRASMENU is set to text_extras_menu
+ 	   see top of this file ... */
          (void) sprintf(tmp, "%s/lib/.%s",
  		       filename, EXTRASMENU);
  	if ((result = check_filename_locale(NULL, tmp, 1)) != NULL)
  		goto found;
+ 	/* EXTRASMENU is absolute specified as normally done
+ 	   during  compile time option -DEXTRASMENU="\"$(TEXT_EXTRAS_MENU)\" */
+ 	(void) sprintf(tmp, "%s", EXTRASMENU);
+ 	if ((result = check_filename_locale(NULL, tmp, 1)) != NULL)
+ 	    goto found;
  #endif
      }
  
