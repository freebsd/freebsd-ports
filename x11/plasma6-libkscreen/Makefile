PORTNAME=	libkscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/hwdata/pnp.ids:misc/hwdata

USES=		cmake compiler:c++11-lib gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		base \
		tools:build

post-patch:
# Looking for pnp.ids
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/edid.cpp

.include <bsd.port.mk>
