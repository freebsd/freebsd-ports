# New ports collection makefile for:    XFree86
# Version required:     3.3.1
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.34 1997/07/17 15:12:59 max Exp $
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3/source/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3/source/
DISTFILES=	X331src-1.tgz X331src-2.tgz

MAINTAINER=	jmz@FreeBSD.ORG

IS_INTERACTIVE=	yes	# configure script asks questions
USE_X11=	yes
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc

pre-install:
	${MKDIR} /usr/X11R6
post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
