*** defaults.c.orig	Thu Jan 13 16:36:03 1994
--- defaults.c	Sun Jan 24 20:50:32 1999
***************
*** 30,38 ****
  #include <X11/Xutil.h>
  #include <X11/Xatom.h>
  #include <X11/Xresource.h>
- #ifdef OW_I18N_L4
  #include <sys/param.h>
- #endif
  
  #include "i18n.h"
  #include "ollocale.h"
--- 30,36 ----
***************
*** 90,97 ****
--- 88,99 ----
  #ifdef SVR4
  	    if (sysinfo(SI_HOSTNAME, hostname, sizeof(hostname)) != -1) {
  #else
+ #ifdef BSD
+ 	    if (0 == gethostname(hostname, sizeof(hostname))) {
+ #else
  	    if (0 == gethostname(hostname, sizeof(hostname), &namelen)) {
  #endif
+ #endif
  		(void) strcat(filename, hostname);
  		fileDB = XrmGetFileDatabase(filename);
  	    }
***************
*** 159,165 ****
  	    return appDB;
      }
  
!     appDB = XrmGetFileDatabase("/usr/lib/X11/app-defaults/Olwm");
      return appDB;
  }
  
--- 161,167 ----
  	    return appDB;
      }
  
!     appDB = XrmGetFileDatabase("/usr/X11R6/lib/X11/app-defaults/Olwm");
      return appDB;
  }
  
