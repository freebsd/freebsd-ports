PORTNAME=	kwin-zones
PORTVERSION=	1.0.13
CATEGORIES=	x11-wm kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Wayland xx-zones for KWin
WWW=		https://invent.kde.org/automotive/kwin-zones

BUILD_DEPENDS=	vulkan-headers>=0:graphics/vulkan-headers \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-server.so:graphics/wayland

USES=		cmake kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	config kwin \
		ecm:build
USE_QT=		base wayland

.include <bsd.port.mk>
