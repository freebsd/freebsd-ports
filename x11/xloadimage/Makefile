# New ports collection makefile for:    xloadimage
# Version required:     4.1
# Date created:         9 January 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.10 1998/06/17 20:12:02 jmz Exp $
#

DISTNAME=	xloadimage.4.1
PKGNAME=	xloadimage-4.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/

MAINTAINER=	jmz@FreeBSD.org

USE_X_PREFIX=	yes

ALL_TARGET=

do-configure:
	cd ${WRKSRC} && make configure </dev/null
	cd ${WRKSRC} && ${ECHO} SYSPATHFILE=${X11BASE}/lib/X11/app-defaults/Xloadimage >> Makefile

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xloadimage uufilter ${X11BASE}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} xloadimagerc ${X11BASE}/lib/X11/app-defaults/Xloadimage
	cd ${WRKSRC} && sed -e s:/usr/lib/X11/Xloadimage:${X11BASE}/lib/X11/app-defaults/Xloadimage: < xloadimage.man |${GZIP_CMD} >${X11BASE}/man/man1/xloadimage.1.gz

.include <bsd.port.mk>
