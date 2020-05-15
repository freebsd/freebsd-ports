# $FreeBSD$

PORTNAME=	polybar
DISTVERSION=	3.4.3
CATEGORIES=	x11
MASTER_SITES=	https://github.com/polybar/polybar/releases/download/${DISTVERSION}/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Fast and easy-to-use status bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xcb-proto>=1.9:x11/xcb-proto
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinotify.so:devel/libinotify \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm

# compiler:c++11-lang is needed for powerpc64
USES=		cmake compiler:c++11-lang gnome localbase:ldflags \
		pkgconfig python:3.5+,build tar xorg

USE_GNOME=	cairo
USE_XORG=	xcb

# Needs libnl to work. Disabling it completely.
CMAKE_OFF=	ENABLE_NETWORK

OPTIONS_DEFINE=		ALSA CURSOR DEBUG GITHUB I3 IPC MPD PULSEAUDIO \
			TESTS XKEYBOARD
OPTIONS_DEFAULT=	CURSOR GITHUB I3 IPC MPD PULSEAUDIO XKEYBOARD
OPTIONS_SUB=		yes

ALSA_DESC=	Shows volume and mute state for Alsa
CURSOR_DESC=	Required for click and scroll settings
GITHUB_DESC=	Shows the unread notification count
I3_DESC=	Uses the i3 IPC to display information
IPC_DESC=	Built-in IPC support
MPD_DESC=	Support for controlling MPD
TESTS_DESC=	Build testsuite
XKEYBOARD_DESC=	Shows the current layout and active indicators

ALSA_CMAKE_BOOL=	ENABLE_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

CURSOR_CMAKE_BOOL=	WITH_XCURSOR
CURSOR_LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor

GITHUB_CMAKE_BOOL=	ENABLE_CURL
GITHUB_LIB_DEPENDS=	libcurl.so:ftp/curl

DEBUG_CMAKE_BOOL=	DEBUG_LOGGER

I3_BUILD_DEPENDS=	${LOCALBASE}/include/i3/ipc.h:x11-wm/i3
I3_CMAKE_BOOL=		ENABLE_I3
I3_LIB_DEPENDS=		libjsoncpp.so:devel/jsoncpp

IPC_CMAKE_BOOL=		BUILD_IPC_MSG

MPD_CMAKE_BOOL=		ENABLE_MPD
MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

PULSEAUDIO_CMAKE_BOOL=		ENABLE_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

# fail while building on poudriere because it needs network access
# during the building process to download googletest on-the-fly.
TESTS_BUILD_DEPENDS=	git>=0:devel/git
TESTS_CMAKE_BOOL=	BUILD_TESTS

XKEYBOARD_CMAKE_BOOL=	ENABLE_XKEYBOARD
XKEYBOARD_LIB_DEPENDS=	libxcb-xkb.so:x11/libxcb

WRKSRC=		${WRKDIR}/${PORTNAME}

do-test-TESTS-on:
	cd ${TEST_WRKSRC} && ${SETENV} BUILD_TESTS=ON \
		${SH} ${WRKSRC}/common/travis/tests.sh

.include <bsd.port.mk>
