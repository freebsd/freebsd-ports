*** src/DesktopConfig.cpp.orig	Mon Sep  5 21:03:05 2005
--- src/DesktopConfig.cpp	Mon Sep 12 22:38:55 2005
***************
*** 22,31 ****
--- 22,32 ----
   * (See the included file COPYING / BSD )
   */
  
  #include "DesktopConfig.h"
  #include "Util.h"
+ #include "sys/stat.h"
  
  //the initilizer list just sets the program defaults for non-necessary options
  DesktopConfig::DesktopConfig(Database db, string ideskrcFile) :
                               AbstractConfig(ideskrcFile)
  {
