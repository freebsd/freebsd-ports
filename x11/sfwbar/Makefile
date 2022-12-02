PORTNAME=	sfwbar
DISTVERSION=	v1.0_beta9
CATEGORIES=	x11

MAINTAINER=	tino.engel@mail.de
COMMENT=	Flexible taskbar application for wayland compositors
WWW=		https://github.com/LBCrion/sfwbar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libwayland-client.so:graphics/wayland \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols

USES=		meson ninja pkgconfig gnome
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	LBCrion

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

.include <bsd.port.mk>
