# New ports collection makefile for:    xloadimage
# Version required:     4.1
# Date created:         9 January 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.7 1996/11/18 11:44:23 asami Exp $
#

DISTNAME=	xloadimage.4.1
PKGNAME=	xloadimage-4.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/

MAINTAINER=	jmz@FreeBSD.org

USE_X11=	yes

ALL_TARGET=

do-configure:
	cd ${WRKSRC} && make configure </dev/null
	cd ${WRKSRC} && ${ECHO} SYSPATHFILE=${X11BASE}/lib/X11/app-defaults/Xloadimage >> Makefile

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xloadimage uufilter ${X11BASE}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} xloadimage uufilter ${X11BASE}/bin
	cd ${WRKSRC} && ${GZIP_CMD} < xloadimage.man >${X11BASE}/man/man1/xloadimage.1.gz

.include <bsd.port.mk>
