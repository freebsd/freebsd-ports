*** src/XImlib2Background.cpp.orig	Tue Sep  6 01:03:34 2005
--- src/XImlib2Background.cpp	Mon Sep 12 22:39:11 2005
***************
*** 23,32 ****
--- 23,33 ----
   */
  
  #include "Database.h"
  #include "XImlib2Background.h"
  #include <X11/Xatom.h>
+ #include "sys/stat.h"
  
  XImlib2Background::XImlib2Background(AbstractContainer * c, AbstractConfig * con): TimerControl(), 
                                                      container(c), config(con),delay(0), mode(0),  save(NULL), show(NULL),
  						    srctime(0), images(""), directory(""), OneShot(false)
  {
