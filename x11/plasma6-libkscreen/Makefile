PORTNAME=	libkscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	${LOCALBASE}/share/hwdata/pnp.ids:misc/hwdata

USES=		cmake compiler:c++11-lib gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	config \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base wayland

post-patch:
# Looking for pnp.ids
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/edid.cpp

.include <bsd.port.mk>
