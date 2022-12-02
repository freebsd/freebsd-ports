PORTNAME=	sfwbar
DISTVERSION=	1.0_beta9
DISTVERSIONPREFIX=	v
CATEGORIES=	x11 wayland

MAINTAINER=	tino.engel@mail.de
COMMENT=	Flexible taskbar application for wayland compositors
WWW=		https://github.com/LBCrion/sfwbar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libwayland-client.so:graphics/wayland \
		libjson-c.so:devel/json-c

USES=		gnome meson pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	LBCrion

SUB_FILES=	pkg-message

.include <bsd.port.mk>
