# New ports collection makefile for:	xcb-util-image
# Date created:		2011-12-16
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	xcb-util-image
PORTVERSION=	0.3.8
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A port of Xlib's XImage and XShmImage functions

LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-util.0:${PORTSDIR}/x11/xcb-util
#BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
#USE_XORG=	xau xdmcp
#USE_AUTOTOOLS=	libtool

GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	GPERF="${LOCALBASE}/bin/gperf"

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
