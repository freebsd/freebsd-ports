# New ports collection makefile for:    XFree86
# Version required:     3.2
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.24 1996/12/07 12:51:19 asami Exp $
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.2/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.2/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.2/source/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.2/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.2/source/
DISTFILES=	X32src-1.tgz X32src-2.tgz

MAINTAINER=	jmz@FreeBSD.ORG

IS_INTERACTIVE=	yes	# configure script asks questions
USE_X11=	yes
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc

post-install:
	chmod u-s ${PREFIX}/bin/SuperProbe
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
