PORTNAME=	libkscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 screen management library
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libwayland-client.so:graphics/wayland
RUN_DEPENDS=	${PNP_IDS_FILE}:misc/hwdata

USES=		cmake compiler:c++11-lib kde:5 pathfix pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	config wayland \
		ecm:build plasma-wayland-protocols:build
USE_QT=		core dbus gui wayland x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcb xrandr

PNP_IDS_FILE=	${LOCALBASE}/share/hwdata/hwdata/pnp.ids

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/hwdata/pnp.ids|${PNP_IDS_FILE}|' ${WRKSRC}/src/edid.cpp

.include <bsd.port.mk>
