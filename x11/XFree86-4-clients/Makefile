# New ports collection makefile for:    XFree86
# Version required:     3.3
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.33 1997/07/14 06:36:30 asami Exp $
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3/source/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3/source/
DISTFILES=	X33src-1.tgz X33src-2.tgz

MAINTAINER=	jmz@FreeBSD.ORG

IS_INTERACTIVE=	yes	# configure script asks questions
USE_X11=	yes
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
