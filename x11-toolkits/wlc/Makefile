# $FreeBSD$

PORTNAME=	wlc
PORTVERSION=	0.0.8
PORTREVISION=	2
CATEGORIES=	x11-toolkits wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland compositor library

DEPRECATED=	Deprecated upstream
EXPIRATION_DATE=	2018-12-31

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LISENSE

BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libwayland-server.so:graphics/wayland \
		libdrm.so:graphics/libdrm \
		libudev.so:devel/libudev-devd \
		libinput.so:x11/libinput \
		libxcb-image.so:x11/xcb-util-image

RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config

USE_GITHUB=	yes
GH_ACCOUNT=	cloudef
GH_TAGNAME=	fa780ce
GH_TUPLE=	cloudef:chck:3f27d2a:chck

USES=		cmake gnome localbase pkgconfig pathfix
USE_XORG=	pixman x11 xcb xcursor xfixes
USE_GL=		egl gbm glesv2
USE_GNOME=	cairo

USE_LDCONFIG=	yes

post-extract:
	@${RM} -r ${WRKSRC}/lib/chck
	@${LN} -s ${WRKSRC_chck} ${WRKSRC}/lib/chck

.include <bsd.port.mk>
