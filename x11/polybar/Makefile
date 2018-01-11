# $FreeBSD$

PORTNAME=	polybar
DISTVERSION=	3.1.0
CATEGORIES=	x11

MAINTAINER=	capt_redbeard@protonmail.com
COMMENT=	Fast and easy-to-use status bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xcb-proto>=1.9:x11/xcb-proto
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util \
		libxcb-image.so:x11/xcb-util-image \
		libinotify.so:devel/libinotify

USES=		cmake:outsource localbase:ldflags pkgconfig python:2.7,build
USE_GITHUB=	yes
GH_ACCOUNT=	jaagr
GH_TUPLE=	jaagr:i3ipcpp:v0.7.1:i3ipcpp/lib/i3ipcpp \
		jaagr:xpp:1.4.0-1-g64bd576:xpp/lib/xpp
USE_GNOME=	cairo
USE_XORG=	xcb

OPTIONS_DEFINE=	ALSA CURL EXAMPLES I3 IPC MPD
OPTIONS_DEFAULT=	ALSA CURL I3 IPC MPD
OPTIONS_SUB=	yes

ALSA_DESC=	Volume control
CURL_DESC=	Github support
I3_DESC=	i3wm support
MPD_DESC=	Support for controlling MPD
IPC_DESC=	i3 IPC support

ALSA_CMAKE_BOOL=	ENABLE_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

CURL_CMAKE_BOOL=	ENABLE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

I3_BUILD_DEPENDS=	${LOCALBASE}/include/i3/ipc.h:x11-wm/i3
I3_CMAKE_BOOL=		ENABLE_I3
I3_LIB_DEPENDS=		libjsoncpp.so:devel/jsoncpp

IPC_CMAKE_BOOL=		BUILD_IPC_MSG

MPD_CMAKE_BOOL=		ENABLE_MPD
MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

post-patch:
	@${REINPLACE_CMD} -e 's|python2|${PYTHON_CMD}|g' ${WRKSRC_xpp}/CMakeLists.txt

.include <bsd.port.mk>
