*** lib/libxview/notify/sys_read.c~	Mon Jun 28 22:18:01 1993
--- lib/libxview/notify/sys_read.c	Tue Nov 22 08:16:11 1994
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
  #include <sys/syscall.h>
  #endif SVR4
