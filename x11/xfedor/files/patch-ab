*** sos.c.bak	Thu May 26 21:59:13 1994
--- sos.c	Tue Sep  3 01:15:19 1996
***************
*** 36,42 ****
  {
  
  	if ((dirsos = getenv("SOS"))==0)
!   	     if (UnixFileNameMode) dirsos = "/usr/local/lib/X11/xfedor" ; 
  	                      else dirsos = "";
  	if (UnixFileNameMode) {
  	   newdirsos = (char *)malloc(strlen(dirsos)+2);
--- 36,42 ----
  {
  
  	if ((dirsos = getenv("SOS"))==0)
! 	     if (UnixFileNameMode) dirsos = DIRSOS;
  	                      else dirsos = "";
  	if (UnixFileNameMode) {
  	   newdirsos = (char *)malloc(strlen(dirsos)+2);
