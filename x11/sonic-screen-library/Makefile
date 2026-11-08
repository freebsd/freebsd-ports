PORTNAME=	sonic-screen-library
DISTVERSION=	6.8.0
CATEGORIES=	x11

COMMENT=	Sonic's screen management software
MAINTAINER=	acm@FreeBSD.org
WWW=		https://github.com/Sonic-DE/sonic-screen-library

LICENSE=	LGPL20

CONFLICTS=	plasma6-libkscreen

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/hwdata/pnp.ids:misc/hwdata

USES=		cmake compiler:c++11-lib gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Sonic-DE

USE_GL=		gl opengl
USE_KDE=	config \
		ecm:build
USE_QT=		base
USE_XORG=	xcb

post-patch:
# Looking for pnp.ids
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/edid.cpp

.include <bsd.port.mk>
