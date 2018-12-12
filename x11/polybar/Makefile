# $FreeBSD$

PORTNAME=	polybar
DISTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Fast and easy-to-use status bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to build: KeyError: 'eventstruct'
BROKEN_armv6=	fails to build: KeyError: 'eventstruct'
BROKEN_armv7=	fails to build: KeyError: 'eventstruct'

BUILD_DEPENDS=	xcb-proto>=1.9:x11/xcb-proto
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinotify.so:devel/libinotify \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm

USES=		cmake:outsource compiler:c++11-lang localbase:ldflags \
		pkgconfig python:2.7,build
USE_GITHUB=	yes
GH_ACCOUNT=	jaagr
GH_TUPLE=	jaagr:i3ipcpp:v0.7.1-4-gd4e4786:i3ipcpp/lib/i3ipcpp \
		jaagr:xpp:1.4.0-4-g00165e1:xpp/lib/xpp
USE_GNOME=	cairo
USE_XORG=	xcb

OPTIONS_DEFINE=	ALSA DEBUG CURL EXAMPLES I3 IPC MPD TESTS
OPTIONS_DEFAULT=	CURL I3 IPC MPD
OPTIONS_SUB=	yes

ALSA_DESC=	Volume control
CURL_DESC=	Github support
I3_DESC=	i3wm support
IPC_DESC=	Built-in IPC support
MPD_DESC=	Support for controlling MPD
TESTS_DESC=	Build testsuite

ALSA_CMAKE_BOOL=	ENABLE_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

CURL_CMAKE_BOOL=	ENABLE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DEBUG_CMAKE_BOOL=	DEBUG_LOGGER

I3_BUILD_DEPENDS=	${LOCALBASE}/include/i3/ipc.h:x11-wm/i3
I3_CMAKE_BOOL=		ENABLE_I3
I3_LIB_DEPENDS=		libjsoncpp.so:devel/jsoncpp

IPC_CMAKE_BOOL=		BUILD_IPC_MSG

MPD_CMAKE_BOOL=		ENABLE_MPD
MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

# fail while building on poudriere because it need network access
# during the building process to download googletest on-the-fly.
TESTS_BUILD_DEPENDS=	git>=0:devel/git
TESTS_CMAKE_BOOL=	BUILD_TESTS

do-test-TESTS-on:
	cd ${TEST_WRKSRC} && ${SETENV} BUILD_TESTS=ON \
		${SH} ${WRKSRC}/common/travis/tests.sh

.include <bsd.port.mk>
