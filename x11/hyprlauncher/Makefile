PORTNAME=	hyprlauncher
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Multipurpose and versatile launcher / picker for Hyprland
WWW=		https://wiki.hypr.land/Hypr-Ecosystem/hyprlauncher/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libhyprwire.so:devel/hyprwire \
		libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libdrm.so:graphics/libdrm \
		libqalculate.so:math/libqalculate \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit
RUN_DEPENDS=	wl-copy:x11/wl-clipboard

USES=		cmake localbase:ldflags pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

LDFLAGS+=	-pthread -linotify

PLIST_FILES=	bin/hyprlauncher

.include <bsd.port.mk>
