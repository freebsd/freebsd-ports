# New ports collection makefile for:    xloadimage
# Version required:     4.1
# Date created:         9 January 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	xloadimage.4.1
PKGNAME=	xloadimage-4.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.freesoftware.com/pub/X11/R5contrib/

MAINTAINER=	jmz@FreeBSD.org

USE_X_PREFIX=	yes
ALL_TARGET=
MAN1=		xloadimage.1

do-configure:
	cd ${WRKSRC} && ${MAKE} configure </dev/null
	cd ${WRKSRC} && ${ECHO} SYSPATHFILE=${PREFIX}/lib/X11/app-defaults/Xloadimage >> Makefile

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xloadimage uufilter ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} xloadimagerc ${PREFIX}/lib/X11/app-defaults/Xloadimage
	cd ${WRKSRC} && ${SED} -e s:/usr/lib/X11/Xloadimage:${PREFIX}/lib/X11/app-defaults/Xloadimage: < xloadimage.man >${PREFIX}/man/man1/xloadimage.1

.include <bsd.port.mk>
