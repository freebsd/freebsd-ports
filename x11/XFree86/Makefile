# New ports collection makefile for:    XFree86
# Version required:     3.2
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.17 1996/02/15 00:53:15 jmz Exp $
#

#######################################################################
#                                                                     #
#                        Configurable Section                         #
#                                                                     #
#######################################################################
#
# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE	=	yes
#######################################################################
DISTNAME	=	xc
PKGNAME		= 	XFree86-3.2
CATEGORIES      =	x11
IS_INTERACTIVE	=	yes
PREFIX		=	/usr/X11R6
MAINTAINER=		jmz@FreeBSD.ORG

do-build:
	@(cd ${WRKSRC}; echo Good night...; make World 2>&1 | tee world.log)
	@touch ${WRKDIR}/.build_done

do-install:
	@(cd ${WRKSRC}; make install; make install.man)
	@touch ${WRKDIR}/.install_done

.include "Makefile.ftp"

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>

