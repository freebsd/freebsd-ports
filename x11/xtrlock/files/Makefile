# Makefile for xtrlock - X Transparent Lock
# This Makefile provided for those of you who lack a functioning xmkmf.
#
# Copyright (C)1993,1994 Ian Jackson
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# $FreeBSD$
#

LDLIBS=-lX11 -lcrypt
CC?=gcc
CFLAGS+=-I${X11BASE}/include -L${X11BASE}/lib
INSTALL=install -c
INSTALL_PROGRAM = ${INSTALL}
INSTPGMFLAGS = -s -o root -m4111
OBJS=xtrlock.o

xtrlock:	xtrlock.o
		${CC} ${CFLAGS} ${LDLIBS} -o xtrlock ${OBJS}

xtrlock.o:	xtrlock.c lock.bitmap mask.bitmap patchlevel.h
	        ${CC} -c ${CFLAGS} xtrlock.c

install:	xtrlock install.man
		$(INSTALL_PROGRAM) $(INSTPGMFLAGS) xtrlock ${PREFIX}/bin

install.man:
		$(INSTALL) -m 644 xtrlock.man ${PREFIX}/man/man1/xtrlock.1

all:            xtrlock
