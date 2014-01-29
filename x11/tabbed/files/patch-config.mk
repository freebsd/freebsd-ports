*** config.mk.orig	2014-01-19 21:53:24.000000000 +0400
--- config.mk	2014-01-19 22:40:13.000000000 +0400
***************
*** 5,15 ****
  
  # paths
  PREFIX = /usr/local
! MANPREFIX = ${PREFIX}/share/man
  
  # includes and libs
! INCS = -I. -I/usr/include
! LIBS = -L/usr/lib -lc -lX11
  
  # flags
  CPPFLAGS = -DVERSION=\"${VERSION}\" -D_BSD_SOURCE
--- 5,15 ----
  
  # paths
  PREFIX = /usr/local
! MANPREFIX = ${PREFIX}/man
  
  # includes and libs
! INCS = -I. -I/usr/local/include
! LIBS = -L/usr/local/lib -lc -lX11
  
  # flags
  CPPFLAGS = -DVERSION=\"${VERSION}\" -D_BSD_SOURCE
***************
*** 21,25 ****
  #LDFLAGS = ${LIBS}
  
  # compiler and linker
! CC = cc
  
--- 21,25 ----
  #LDFLAGS = ${LIBS}
  
  # compiler and linker
! CC?= cc
