PORTNAME=	disman
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	0.527.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt/C++ display management library
WWW=		https://github.com/winft/disman

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN=		fails to build with wrapland 0.600

TEST_DEPENDS=	${qt-testlib_PORT:T}>0:${qt-testlib_PORT}

USES=		cmake:testing kde:5 pathfix qt:5
USE_GITHUB=	yes
USE_KDE=	ecm:build coreaddons
USE_LDCONFIG=	yes
USE_QT=		qmake:build buildtools:build core dbus gui
GH_ACCOUNT=	winft
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME:S/@/-/}
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

WAYLAND_LIB_DEPENDS=	libWraplandClient.so:graphics/wrapland
WAYLAND_USE=		KDE=wayland
WAYLAND_CMAKE_BOOL_OFF=	${KF5Wayland Wrapland:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/}

X11_USES=		xorg
X11_USE=		QT=x11extras XORG=xcb
X11_CMAKE_BOOL_OFF=	${Qt5X11Extras XCB:L:S/^/CMAKE_DISABLE_FIND_PACKAGE_/}

post-patch:
# Respect PREFIX for hwdata
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/backends/edid.cpp

.include <bsd.port.mk>
