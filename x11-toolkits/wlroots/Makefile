# $FreeBSD$

PORTNAME=	wlroots
DISTVERSION=	0.9.1
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

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl gbm glesv2
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dexamples=false

# XXX Drop after FreeBSD 12.0 EOL
.if exists(/usr/lib/clang/8.0.0)
# https://github.com/swaywm/wlroots/issues/1450
LLD_UNSAFE=	yes
.endif

OPTIONS_DEFINE=	CONSOLEKIT FREERDP X11
OPTIONS_DEFAULT=FREERDP X11
OPTIONS_SUB=	yes

CONSOLEKIT_DESC=	DRM sessions without root using ConsoleKit2
CONSOLEKIT_PATCH_SITES=	https://github.com/myfreeweb/${GH_PROJECT}/commit/:ck2
CONSOLEKIT_PATCHFILES=	606b009fcdd1.patch:-p1:ck2 # see #1467 upstream
CONSOLEKIT_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libconsolekit.so:sysutils/consolekit2
CONSOLEKIT_MESON_ENABLED=	consolekit2
.if make(makesum)
.MAKEFLAGS:		WITH+=CONSOLEKIT
.endif

FREERDP_DESC=	RDP backend with freerdp
FREERDP_LIB_DEPENDS=	libfreerdp2.so:net/freerdp
FREERDP_MESON_ENABLED=	freerdp

X11_LIB_DEPENDS=libxcb-errors.so:x11/xcb-util-errors \
		libxcb-icccm.so:x11/xcb-util-wm
X11_RUN_DEPENDS=Xwayland:x11-servers/xwayland
X11_USE=	XORG=x11,xcb
X11_MESON_ENABLED=x11-backend xcb-icccm xwayland

post-patch:
# Ignore unused dependencies
	@${REINPLACE_CMD} '/examples/d' ${WRKSRC}/meson.build

.include <bsd.port.mk>
