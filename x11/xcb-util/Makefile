# New ports collection makefile for:   xcb-util
# Date created:                October 16, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	xcb-util
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A module with libxcb/libX11 extension/replacement libraries

LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb
BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_XORG=	xau xdmcp
USE_AUTOTOOLS=	libtool:15

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GPERF="${LOCALBASE}/bin/gperf"

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
