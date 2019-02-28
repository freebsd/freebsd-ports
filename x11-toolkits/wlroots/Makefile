# $FreeBSD$

PORTNAME=	wlroots
DISTVERSION=	0.4.1
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modular Wayland compositor library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.17:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-egl.so:graphics/wayland \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		egl gbm glesv2
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dexamples=false

# https://github.com/swaywm/wlroots/issues/1450
LLD_UNSAFE=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_LIB_DEPENDS=libxcb-errors.so:x11/xcb-util-errors \
		libxcb-icccm.so:x11/xcb-util-wm
X11_RUN_DEPENDS=Xwayland:x11-servers/xwayland
X11_USE=	XORG=x11,xcb
X11_MESON_ENABLED=x11-backend xcb-icccm xwayland

post-patch:
# Ignore unused dependencies
	@${REINPLACE_CMD} '/examples/d' ${WRKSRC}/meson.build

.include <bsd.port.mk>
