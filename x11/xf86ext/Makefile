# New ports collection makefile for:   XF86Ext
# Date Created:			7 May 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86ext
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/X11R6.7.0/src/ \
		${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R6.7/tars
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Header files for miscellaneous XFree86 X Extensions

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

PREFIX?=	${X11BASE}
DIST_SUBDIR=	xorg
WRKSRC=		${WRKDIR}/xc/include/extensions
EXTRACT_AFTER_ARGS= | ${TAR} -xf - xc/include/extensions
NO_BUILD=	yes

DEST=${PREFIX}/include/X11/extensions

do-install:
	${INSTALL_DATA} ${WRKSRC}/xf86mscstr.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86misc.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86vmstr.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86vmode.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86dga1str.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86dga1.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86dgastr.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/xf86dga.h ${DEST}

.include <bsd.port.mk>
