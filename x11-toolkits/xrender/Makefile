# New ports collection makefile for:   xrender
# Date Created:			2 Jul, 2003
# Whom:				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xrender
PORTVERSION=	0.8.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XRender extension for XFree86

BUILD_DEPENDS=	${X11BASE}/lib/pkgconfig/render.pc:${PORTSDIR}/x11-toolkits/render

USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${X11BASE}/lib/pkgconfig

INSTALLS_SHLIB=	yes

pre-build:
	@(cd ${WRKSRC}; ./configure ${CONFIGURE_ARGS} ${CONFIGURE_ENV})

.include <bsd.port.mk>
