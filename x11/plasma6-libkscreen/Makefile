PORTNAME=	libkscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${PNP_IDS_FILE}:misc/hwdata

USES=		cmake compiler:c++11-lib gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	config \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base wayland
USE_XORG=	xcb

PNP_IDS_FILE=	${LOCALBASE}/share/hwdata/pnp.ids

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/hwdata/pnp.ids|${PNP_IDS_FILE}|' ${WRKSRC}/src/edid.cpp

.include <bsd.port.mk>
