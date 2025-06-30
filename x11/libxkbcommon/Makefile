PORTNAME=	libxkbcommon
DISTVERSION=	1.8.1
PORTREVISION=	3
CATEGORIES=	x11

PATCH_SITES=	https://github.com/xkbcommon/libxkbcommon/commit/
PATCHFILES=	d7e112febb7ab756563da6eced0a650396be5945.patch:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Keymap handling library for toolkits and window systems
WWW=		https://xkbcommon.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xkeyboard-config>0:x11/xkeyboard-config

USES=		bison compiler:c11 cpe gnome meson pkgconfig python:test \
		shebangfix
CPE_VENDOR=	xkbcommon
SHEBANG_FILES=	test/xkeyboard-config-test.py.in \
		test/*.py
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	xkbcommon
GH_TAGNAME=	${GH_ACCOUNT}-${DISTVERSION}

HAS_SYMBOL_VERSION=	${PREFIX}/lib/libxkbregistry.so.0.8.1

MESON_ARGS=	-Denable-docs=false \
		-Dx-locale-root="${PREFIX}/lib/X11/locale"

OPTIONS_DEFINE=	EVDEV WAYLAND X11
OPTIONS_DEFAULT=EVDEV WAYLAND X11
OPTIONS_SUB=	yes

EVDEV_DESC=		Interactive debugger for XKB keymaps for evdev
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_USES=		localbase

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_TRUE=	enable-wayland

X11_USES=	xorg
X11_USE=	XORG=xcb
X11_MESON_TRUE=	enable-x11

.include <bsd.port.mk>
