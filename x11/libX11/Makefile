# New ports collection makefile for:   libX11
# Date Created:			28 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libX11
PORTVERSION=	6.2.1.p2
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/~anholt/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 library

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${X11BASE}/libdata/pkgconfig/xtrans.pc:${PORTSDIR}/x11/libXtrans \
		${X11BASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+= --enable-xdmauth
CFLAGS+=	-DMALLOC_0_RETURNS_NULL -DXLOCALEDIR="\"${X11BASE}/locale\""
WRKSRC=		${WRKDIR}/${PORTNAME}-6.2.1

INSTALLS_SHLIB=	yes

# This is a hack until we get locale files included with libX11.
post-install:
	${LN} -shf ${PREFIX}/lib/X11/locale ${PREFIX}/share/X11/locale

.include <bsd.port.mk>
