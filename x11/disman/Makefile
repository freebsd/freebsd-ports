PORTNAME=	disman
DISTVERSIONPREFIX=	v
DISTVERSION=	0.601.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ display management library
WWW=		https://github.com/winft/disman

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake:testing kde:6 pathfix qt:6
USE_GITHUB=	yes
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_QT=		base
GH_ACCOUNT=	winft
LDFLAGS+=	-Wl,--as-needed # GL, xkbcommon
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

WAYLAND_LIB_DEPENDS=	libWraplandClient.so:graphics/wrapland
WAYLAND_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Wrapland

X11_USES=		xorg
X11_USE=		XORG=xcb
X11_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_XCB

post-patch:
# Respect PREFIX for hwdata
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/backends/edid.cpp

.include <bsd.port.mk>
