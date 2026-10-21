PORTNAME=	cosmic-bg
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	x11

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	COSMIC service to apply wallpapers to displays
WWW=		https://github.com/pop-os/cosmic-bg

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libdav1d.so:multimedia/dav1d \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	cosmic-icons>=${PORTVERSION}:x11-themes/cosmic-icons

USES=		cargo gl pkgconfig
USE_GL=		egl
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_TUPLE=	pop-os:iced:39d3c99d1315e9a3db76fa8b32aa91e439c38b32:iced/../${WRKSRC_crate_build_helpers:T}/iced

PLIST_FILES=	bin/cosmic-bg \
		share/cosmic/com.system76.CosmicBackground/v1/all

post-install:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/share/cosmic/com.system76.CosmicBackground/v1
	${INSTALL_DATA} ${WRKSRC}/data/v1/all \
		${STAGEDIR}${PREFIX}/share/cosmic/com.system76.CosmicBackground/v1

.include <bsd.port.mk>
