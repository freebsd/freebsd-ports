PORTNAME=	hyprshutdown
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Graceful shutdown utility for Hyprland
WWW=		https://github.com/hyprwm/hyprshutdown

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glaze>=6.1.0:devel/glaze
LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libdrm.so:graphics/libdrm \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit

USES=		cmake pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
