*** lib/libxview/notify/sys_select.c~	Mon Jun 28 22:18:11 1993
--- lib/libxview/notify/sys_select.c	Tue Nov 22 08:20:27 1994
***************
*** 15,21 ****
--- 15,25 ----
   */
  
  #ifndef SVR4
+ #ifndef __FreeBSD__
  #include <syscall.h>
+ #else
+ #include <sys/syscall.h>
+ #endif
  #else SVR4
  #include <values.h>
  #include <sys/time.h>
