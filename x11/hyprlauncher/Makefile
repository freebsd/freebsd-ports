PORTNAME=	hyprlauncher
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
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
		libdrm.so:graphics/libdrm \
		libqalculate.so:math/libqalculate \
		libfontconfig.so:x11-fonts/fontconfig \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit
RUN_DEPENDS=	wl-copy:x11/wl-clipboard

USES=		cmake pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

LDFLAGS+=	-pthread

PLIST_FILES=	bin/hyprlauncher

# XXX Drop after FreeBSD 14.* EOL around 2028-11-30
# https://cgit.freebsd.org/src/commit/?id=3965de642c29
.if !exists(/usr/include/sys/inotify.h)
LIB_DEPENDS+=	libinotify.so:devel/libinotify
USES+=		localbase:ldflags
LDFLAGS+=	-linotify
.endif

.include <bsd.port.mk>
