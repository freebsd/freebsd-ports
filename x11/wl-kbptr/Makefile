PORTNAME=	wl-kbptr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Control the mouse pointer with the keyboard on Wayland
WWW=		https://github.com/moverest/wl-kbptr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	moverest
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
